#ifndef RAWMOUSE_HH
#define RAWMOUSE_HH

///////////////////////////////////////////////////////////////////////////////
// rawmouse.hh
//
// Unaccelerated, raw mouse delta — unified interface, platform-split impl.
//
//   Windows / Linux : sf::Event::MouseMovedRaw  (SFML built-in)
//   macOS           : CGGetLastMouseDelta()     (CoreGraphics, pure C)
//
//   The main difference between the MacOS API and the SFML API is that
//   the former is event-based, the latter is poll-based.
//   To find a common ground, the resulting API is split into two calls:
//   - RawMouse::event (): to be called whenever a SFML MouseMovedRaw
//                         event is generated.
//   - RawMouse::delta (): to be called outside of the event loop,
//                         whenever a new frame is computed.
//
// CMake (macOS only): include the CoreGraphics" framwork.
//
// Usage:
//   RawMouse raw_mouse;
//   window.setMouseCursorGrabbed (true);
//   window.setMouseCursorVisible (false);
//
//   // Inside the event loop — caller filters the event type:
//   while (auto event = window.pollEvent ()) {
//       if (const auto* raw = event->getIf<sf::Event::MouseMovedRaw> ())
//           raw_mouse.event(*raw);          // no-op on macOS
//       // ... handle other events ...
//   }
//
//   // Once per frame, after the event loop:
//   sf::Vector2f delta = raw_mouse.delta ();
//   phi   += delta.y * sensitivity;
//   theta += delta.x * sensitivity;
//
///////////////////////////////////////////////////////////////////////////////

#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

#ifdef __APPLE__
#  include <CoreGraphics/CGRemoteOperation.h>
#  include <cstdint>
#endif



namespace fcg
{

    class RawMouse
    {

        // ─────────────────────────────────────────────────────────────────────────────
        // macOS — CGGetLastMouseDelta (pure C, no Objective-C required)
        // ─────────────────────────────────────────────────────────────────────────────
#ifdef __APPLE__
    private:
        bool first_call = true;

    public:
        /// No-op: on macOS deltas are polled inside consumeDelta(), not fed
        /// from events. Defined so the call-site compiles identically on all
        /// platforms — the caller still does the getIf<> filtering.
        void event (const sf::Event::MouseMovedRaw& /* event */) {}

        /// Returns the raw, unaccelerated hardware delta since the last call.
        sf::Vector2f delta ()
        {
            int32_t dx = 0;
            int32_t dy = 0;
            CGGetLastMouseDelta (&dx, &dy);

            // First-call quirk: CGGetLastMouseDelta reports the
            // displacement between the mouse position at program
            // launch and the current position on its very first
            // invocation. We discard that value and return zero to
            // prevent a violent camera jump at startup.
            if (first_call) {
                first_call = false;
                return sf::Vector2f {0.f, 0.f};
            }

            return sf::Vector2f {static_cast<float>(dx), static_cast<float>(dy)};
        }


        // ─────────────────────────────────────────────────────────────────────────────
        // Windows / Linux — sf::Event::MouseMovedRaw
        // ─────────────────────────────────────────────────────────────────────────────
#else
    private:
        sf::Vector2f accumulated_delta {0.f, 0.f};

    public:
        /// Accumulates the raw, unaccelerated delta from a MouseMovedRaw event.
        /// The caller is responsible for extracting the correct event variant
        /// before invoking this (via getIf<sf::Event::MouseMovedRaw>()).
        void event (const sf::Event::MouseMovedRaw& e)
        {
            accumulated_delta.x += static_cast<float> (e.delta.x);
            accumulated_delta.y += static_cast<float> (e.delta.y);
        };

    /// Returns the total raw delta accumulated since the last call,
    /// then resets the accumulator to zero.
        sf::Vector2f delta ()
        {
            sf::Vector2f delta = accumulated_delta;
            accumulated_delta = sf::Vector2f {0.f, 0.f};
            return delta;
        }
#endif
    };
}

#endif
