# MultiWindowBug
Weird drawing resizing bug using openGL 4.1 

for some reason calling:     
ofGLFWWindowSettings settings;
settings.setGLVersion(4,1);

Makes it so window resize events from the main window effect drawing of FBO's on a second window...?