#include "window.h"

static void glfw_error_callback(int error, const char* description);

Scene* Window::currentScene = nullptr;

Window::Window(int winWidth, int winHeight, std::string winTitle){
    width = winWidth;
    height = winHeight;
    title = winTitle;
}

Window& Window::getInstance(){
    static Window INSTANCE = Window(1155, 648, "Title");
    return INSTANCE;
}

void Window::gl_init(){

    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        std::cout << "Failed to init glfw";

    // Configurate the glfw
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    // For debug usage
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    // Create window with graphics context
    window = glfwCreateWindow(Window::getInstance().width, Window::getInstance().height, Window::getInstance().title.c_str(), nullptr, nullptr);
    if (window == nullptr)
        std::cout <<  "Filed to create window";
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Show the window
    glfwShowWindow(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cout<< "Failed to init glad";

    // enable debug
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

    changeScene(0);// set to default scene
}

void Window::gl_end(){
    // Terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::imgui_init(){

    const char* glsl_version = "#version 130";
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
    //io.ConfigViewportsNoAutoMerge = true;
    //io.ConfigViewportsNoTaskBarIcon = true;
    io.Fonts->AddFontFromFileTTF("assets\\fonts\\ttf\\KNBobohei-Bold.ttf"
                            , 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());

    // Setup Dear ImGui style
    ImGui::StyleColorsClassic();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void Window::imgui_end(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Window::changeScene(int sceneIndex){
    currentScene = new Scene();
    switch (sceneIndex)
    {
    case 0:
        currentScene = new gameplayScene();
        currentScene->init();
        break;
    case 1:
        currentScene = new demoScene();
        currentScene->init();
        break;
    default:
        assert("Unable to locate scene");
        break;
    }
}

void Window::loop(){

    float startTime = ImGui::GetTime();
    float endTime = ImGui::GetTime();
    float s = -1;

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();


        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // the start of imgui update
        if(s >= 0)
            currentScene->gui(s);

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(window);

        // The start of scene update
        if(s >= 0)
            currentScene->update(s);

        glfwSwapBuffers(window);

        endTime = ImGui::GetTime();
        s = endTime - startTime;
        startTime = ImGui::GetTime();
    }
}

int Window::run(){
    gl_init();
    imgui_init();
    
    loop();

    imgui_end();
    gl_end();

    return 0;
}

void Window::setColor(ImVec4 color){clear_color = color;}
void Window::setColor(float r, float g, float b, float a){clear_color = ImVec4(r, g, b, a);}
ImVec4 Window::getColor(){return clear_color;}

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}