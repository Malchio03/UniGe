#ifndef HOT_SHADERS_HH
#define HOT_SHADERS_HH

#include <string>
#include <fstream>
#include <filesystem>



// returns a C++ string loaded with the contents of a whole file
inline std::string read_file (const std::string filename)
{
    // open file
    std::ifstream file (filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error. Failed to open file: " << filename << std::endl;
        exit (1);
    }

    // Reserve space according to size
    std::string s;
    s.reserve (std::filesystem::file_size (filename));

    // Read file content
    s.assign (std::istreambuf_iterator<char> (file),
              std::istreambuf_iterator<char> ());

    return s;
}



// get OpenGL log errors when compiling or linking shaders
using glGetIv_func = void (*) (GLuint, GLenum, GLint*);
using glGetInfoLog_func = void (*) (GLuint, GLsizei, GLsizei*, GLchar*);
inline std::string getInfoLog(GLuint object, 
                              glGetIv_func get_iv,
                              glGetInfoLog_func get_infolog)
{
    // get length
    GLint loglen = 0;
    get_iv (object, GL_INFO_LOG_LENGTH, &loglen);

    if (loglen == 0)
        return std::string ();

    // reserve size and retrieve
    std::string info_log;
    info_log.resize (loglen);
    get_infolog (object, loglen, nullptr, info_log.data());

    // Remove null terminator
    if (!info_log.empty() && info_log.back() == '\0') {
        info_log.pop_back ();
    }

    return info_log;
}




class Shaders
{
public:
    GLuint program;

    Shaders () {
        load ();
    }


    Shaders (const std::string vertex_file, const std::string fragment_file) {
        load (vertex_file, fragment_file);
    }


    ~Shaders () {
        clean ();
    }


    void load ()
    {
        const char* vertex_source =
            "#version 410 core\n"
            "layout(location = 0) in vec3 vp;"
            "void main() {"
            "  gl_Position = vec4 (vp, 1.0);"
            "}";
        const char* fragment_source =
            "#version 410 core\n"
            "out vec4 frag_colour;"
            "void main() {"
            "  frag_colour = vec4 (0.8, 0.1, 0.0, 1.0);"
            "}";

        if (!compile_attach_link (&vertex_source, &fragment_source))
            exit (1);
    }


    void load (const std::string vertex_file, const std::string fragment_file)
    {
        const std::string vertex_string = read_file (vertex_file);
        const std::string fragment_string = read_file (fragment_file);
        const char* vertex_source = vertex_string.c_str ();
        const char* fragment_source = fragment_string.c_str ();

        if (!compile_attach_link (&vertex_source, &fragment_source)) {
            std::cerr << "WARNING (Shaders): dynamic loading failed, reverting to static fallback shader."<< std::endl;
            load ();
        }
    }


    void clean ()
    {
        glDeleteProgram (program);
    }


    void reload (const std::string vertex_file, const std::string fragment_file)
    {
        clean ();
        load (vertex_file, fragment_file);
    }


    bool compile_attach_link (const char** vertex_source_ptr,
                              const char** fragment_source_ptr)
    {
        int params = false;

        // copmile vertex shader
        GLuint vertex = glCreateShader (GL_VERTEX_SHADER);
        glShaderSource (vertex, 1, vertex_source_ptr, NULL);
        glCompileShader (vertex);
        // check for errors
        params = -1;
        glGetShaderiv (vertex, GL_COMPILE_STATUS, &params);
        if (!params) {
            std::cerr << "Error compiling vertex shader: "
                      << getInfoLog (vertex, glGetShaderiv, glGetShaderInfoLog)
                      << std::endl;
            return false;
        }

        // compile fragment shader
        GLuint fragment = glCreateShader (GL_FRAGMENT_SHADER);
        glShaderSource (fragment, 1, fragment_source_ptr, NULL);
        glCompileShader (fragment);
        // check for errors
        glGetShaderiv (fragment, GL_COMPILE_STATUS, &params);
        if (!params) {
            std::cerr << "Error compiling fragment shader: "
                      << getInfoLog (fragment, glGetShaderiv, glGetShaderInfoLog)
                      << std::endl;
            return false;
        }

        // attach & link
        program = glCreateProgram ();
        glAttachShader (program, fragment);
        glAttachShader (program, vertex);
        glLinkProgram (program);
        // check for errors
        glGetProgramiv (program, GL_LINK_STATUS, &params);
        if (!params) {
            std::cerr << "Error linking shaders: "
                      << getInfoLog (program, glGetProgramiv, glGetProgramInfoLog)
                      << std::endl;
            return false;
        }

        // once shaders are attached, they can be deleted to free up memory
        glDeleteShader (vertex);
        glDeleteShader (fragment);

        return true;
    }

    void use ()
    {
        glUseProgram (program);
    }

    // if the need to stop the program arises, this is how to do it
    // void stop ()
    // {
    //     glUseProgram (0);
    // }
};

#endif
