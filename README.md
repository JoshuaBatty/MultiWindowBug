# MultiWindowBug
Weird drawing resizing bug using openGL 3.2 + 

for some reason calling:     
ofGLFWWindowSettings settings;
settings.setGLVersion(3,2);

Makes it so window resize events from the main window effect drawing of FBO's on a second window...?