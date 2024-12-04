//
//  main.cpp
//  SDL_Refresher
//
//  Created by Juzer Baatwala on 02/12/24.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

//user defined structs
struct Circle{
    int xPos;
    int yPos;
    int radius;
    Uint32 color;
    
};
//
bool SDL_Initialize();
SDL_Window* createWindow(int HEIGHT,int WIDTH);
SDL_Renderer* createRenderer(SDL_Window *window);
void SDL_CleanUp(SDL_Window* window,SDL_Renderer* renderer,TTF_Font* font);
void createCircle(SDL_Renderer* renderer,int xPos,int yPos,int radius,Uint32 color);
bool InitializeText();
TTF_Font* createFont();
SDL_Texture* textSurfaceCreate(TTF_Font* fontptr,SDL_Color color,SDL_Renderer* renderer);
//global color value
Uint32 colorValCircleGlobal = 0xFFFFFFFF;
//
bool isColored=true; //simulate color change
//main function
int main(int argc, const char * argv[]) {
    int iteration=0;
    int fixedCircleSpeed=10;
    // insert code here...
    std::cout<<"Animating circles in SDL Program";
    bool init=SDL_Initialize();
    if(!init){
        std::cout<<"SDL Initialization failed"<<std::endl;
        std::cout<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::cout<<"SDL Initialisation successfull"<<std::endl;
    }
    //initialize text
    bool initText = InitializeText();
    if (!initText) {
        std::cout<<"SDL Text Initialization failed"<<std::endl;
        std::cout<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }
    SDL_Window* windowptr = createWindow(1000,1000);
    if(!windowptr){
        std::cout<<"SDL window creation failed"<<std::endl;
        std::cout<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::cout<<"window creeated"<<std::endl;
    }
    SDL_Renderer* rendererptr = createRenderer(windowptr);
    if(!rendererptr){
        std::cout<<"SDL renderer creation failed"<<std::endl;
        std::cout<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }
    else{
        std::cout<<"renderer creeated"<<std::endl;
    }
    //load text
    TTF_Font* fontptr=createFont();
    if (!fontptr) {
        std::cout<<"SDL font(text) creation failed"<<std::endl;
        std::cout<<SDL_GetError()<<std::endl;
        return EXIT_FAILURE;
    }
    //font setup color
    SDL_Color color ={255,255,255,255};
    //get textTexture
    SDL_Texture* textTexture=textSurfaceCreate(fontptr,color,rendererptr);
    //get the actuall renderer width and height
    int actualHeight,actualWidth;
    SDL_GetRendererOutputSize(rendererptr, &actualWidth, &actualHeight);
    //instance of the circles
    Circle circle1 ={100,100,100,colorValCircleGlobal};
    Circle circle2 ={actualWidth-100,300,100,colorValCircleGlobal};
    Circle circle3 ={100,500,100,colorValCircleGlobal};
    Circle circle4 ={actualWidth-100,700,100,colorValCircleGlobal};
    Circle circle5 ={100,900,100,colorValCircleGlobal};
    Circle circle6 ={actualWidth-100,1100,100,colorValCircleGlobal};
    Circle circle7 ={100,1300,100,colorValCircleGlobal};
    Circle circle8 ={actualWidth-100,1500,100,colorValCircleGlobal};
    
    bool isRunning= true;
    SDL_Event event;
    while (isRunning) {
        if(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    std::cout<<"User requested exit";
                    //SDL_CleanUp(windowptr, rendererptr, fontptr);
                    isRunning=false;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym==SDLK_SPACE) {
                        std::cout<<"SpaceBar detected!, re-setting animation"<<std::endl;
                        fixedCircleSpeed=10;
                    }
                    if (event.key.keysym.sym==SDLK_a) {
                        fixedCircleSpeed+=5;
                        std::cout<<"A detected!, increasing animation speed"<<fixedCircleSpeed<<std::endl;
                    }
                    
                    break;
            }
        }
        SDL_SetRenderDrawColor(rendererptr, 0, 0, 0, 255);
        SDL_RenderClear(rendererptr);
        createCircle(rendererptr, circle1.xPos, circle1.yPos, circle1.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle2.xPos, circle2.yPos, circle2.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle3.xPos, circle3.yPos, circle3.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle4.xPos, circle4.yPos, circle4.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle5.xPos, circle5.yPos, circle5.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle6.xPos, circle6.yPos, circle6.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle7.xPos, circle7.yPos, circle7.radius,colorValCircleGlobal);
        createCircle(rendererptr, circle8.xPos, circle8.yPos, circle8.radius,colorValCircleGlobal);
        //circle animation speed
        circle1.xPos+=fixedCircleSpeed;
        circle2.xPos-=fixedCircleSpeed;
        circle3.xPos+=fixedCircleSpeed;
        circle4.xPos-=fixedCircleSpeed;
        circle5.xPos+=fixedCircleSpeed;
        circle6.xPos-=fixedCircleSpeed;
        circle7.xPos+=fixedCircleSpeed;
        circle8.xPos-=fixedCircleSpeed;
        
        //loop circles
        if (circle1.xPos>actualWidth+circle1.radius) {
            iteration+=1;
            circle1.xPos= -circle1.radius;
            fixedCircleSpeed+=5;
            std::cout<<"Iteration completed - "<<iteration<<std::endl;
            std::cout<<"Speed - "<<fixedCircleSpeed<<std::endl;
            if(fixedCircleSpeed>2000){
                std::cout<<"Speed Reset"<<std::endl;
                fixedCircleSpeed=10;
                
            }
        }
        if (circle2.xPos<-circle2.radius) {
            circle2.xPos=actualWidth+circle2.radius;
        }
        if (circle3.xPos>actualWidth+circle3.radius) {
            circle3.xPos= -circle3.radius;
        }
        if (circle4.xPos<-circle4.radius) {
            circle4.xPos=actualWidth+circle4.radius;
        }
        if (circle5.xPos>actualWidth+circle5.radius) {
            circle5.xPos= -circle5.radius;
        }
        if (circle6.xPos<-circle6.radius) {
            circle6.xPos=actualWidth+circle6.radius;
        }
        if (circle7.xPos>actualWidth+circle7.radius) {
            circle7.xPos= -circle7.radius;
        }
        if (circle8.xPos<-circle8.radius) {
            circle8.xPos=actualWidth+circle8.radius;
        }
        //issue-change color after 2000th iteration XCODE gives warning /Users/juzerbaatwala/Documents/sdl-xcode/SDL_Refresher/SDL_Refresher/main.cpp:178:36 Implicit conversion from 'long' to 'Uint32' (aka 'unsigned int') changes value from 1095216660480 to 0

        if (fixedCircleSpeed > 100 && isColored==false) {
            colorValCircleGlobal = 0xFF0000FF; // Change color to red // Proper 32-bit color value
            std::cout << "Color changed after 2000 iterations!" << std::endl;
            isColored=true;
        }

        SDL_Rect textRect = {100, 100, 500, 100}; // x, y, width, height
        SDL_RenderCopy(rendererptr, textTexture, nullptr, &textRect);
        SDL_RenderPresent(rendererptr);
        SDL_Delay(16);
    }
    SDL_CleanUp(windowptr,rendererptr,fontptr); //xcode giving error this wont be executed why?
    return EXIT_SUCCESS;
}
bool SDL_Initialize(){
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        return true;
    }
    return false;
}
SDL_Window* createWindow(int HEIGHT,int WIDTH){
    SDL_Window* window = SDL_CreateWindow("DemoWindow",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    return window;
    
}
SDL_Renderer *createRenderer(SDL_Window* window){
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return renderer;
    
}
void SDL_CleanUp(SDL_Window *window,SDL_Renderer* renderer,TTF_Font* font){
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    
}
void createCircle(SDL_Renderer* renderer,int xPos,int yPos,int radius,Uint32 color){
    circleColor(renderer, xPos, yPos, radius, color);
}

bool InitializeText(){
    if (TTF_Init()==0) {
        std::cout<<"Text Initialisation success!"<<std::endl;
        return true;
    }
    return false;
}
TTF_Font* createFont(){
    TTF_Font* font = TTF_OpenFont("/Users/juzerbaatwala/Documents/sdl-xcode/SDL_Refresher/SDL_Refresher/PixeloidSans-mLxMm.ttf", 24);
    return font;
}
SDL_Texture* textSurfaceCreate(TTF_Font* fontptr,SDL_Color color,SDL_Renderer* renderer){
    SDL_Surface* textSurface = TTF_RenderText_Solid(fontptr, "SPACE TO RESTART , A TO ACCELERATE", color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface); // We no longer need the surface
    return textTexture;
    
}
