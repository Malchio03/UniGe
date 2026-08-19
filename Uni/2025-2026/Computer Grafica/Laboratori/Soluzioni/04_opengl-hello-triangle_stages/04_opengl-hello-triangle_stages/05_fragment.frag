#version 410 core

uniform vec3 mod_color;
in vec3 interpolated_color;
out vec4 fragment_color;


// unit clamping a v3
vec3 clamp3u (vec3 v)
{
    return clamp (v, vec3 (0.0), vec3 (1.0));
}

void main()
{
    // return the modified color for the fragment
    fragment_color = vec4 (clamp3u (interpolated_color + mod_color), 1.0);
}

/************

  WARNING:

  Color manipulation and perception can be a very complex topic.
  Direct modification of RGB colors, such as the one implemented in
  this fragment when `interpolated_color` and `mod_color` are summed
  together, usually gives very unintuitive results. For now, we just
  clamp everything back into the [0.0,1.0] range.

  Any color manipulation in real programs, though, should be performed
  only after taking into account the following two suggestions:

  1) To perform most basic lightness or saturation manipulations, the
  obvious thing to do should be to at least convert the RGB color to
  the HSV or HSL color spaces, perform the operation in the new space,
  and convert the color back to RGB.

  2) In fact, even HSL/HSV are far from a good solution, and manipulation
  of colors in these spaces still produces a lot of unexpected
  results. If perceptual consistence is needed or desired, only more
  complex solutions such as the CIELAB and CIELCh color spaces can
  provide something better.

*************/
