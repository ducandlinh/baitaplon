#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";

void logErrorAndExit(const char* msg, const char* error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logErrorAndExit("SDL_Init", SDL_GetError());

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //full screen
    //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        logErrorAndExit( "SDL_image error:", IMG_GetError());

    return window;
}

SDL_Renderer* createRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

    if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    return renderer;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    IMG_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void renderTexture(SDL_Texture *texture, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = 200;
	dest.h = 300;
	//SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture, NULL, &dest);

}


void renderTexture1(SDL_Texture *texture1, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = 50;
	dest.h = 70;
	//SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture1, NULL, &dest);

}

void renderTexture2(SDL_Texture *texture2, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = 1000;
	dest.h = 600;
	//SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture2, NULL, &dest);

}

void renderTexture3(SDL_Texture *texture3, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = 150;
	dest.h = 150;
	//SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture3, NULL, &dest);

}

void renderTexture4(SDL_Texture *texture4, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = 150;
	dest.h = 120;
	//SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture4, NULL, &dest);

}

void renderTexture5(SDL_Texture *texture5, int x, int y, SDL_Renderer* renderer)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	dest.w = 150;
	dest.h = 60;
	//SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(renderer, texture5, NULL, &dest);

}



int randomfence(){

srand(time(0));

int r = rand() % 4;

return r;

}


int getUserInput()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if ((e.type == SDL_QUIT) || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
//            unload_SDL_And_Images();
            exit(1);
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_UP) {

            return 2;

        }

         if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT) {

            return 3;

        }


        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT) {

            return 4;

        }

         if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_DOWN) {

            return 5;

        }

    }
}

SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
	if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

	return texture;
}

// ham tinh thoi gian

uint64_t timeSinceEpochMillisec() {
  using namespace std::chrono;
  return duration_cast<seconds>(system_clock::now().time_since_epoch()).count();
}

void destroy(){

SDL_Texture *texture;
SDL_Texture *texture1;
SDL_Texture *texture2;
SDL_Texture *texture3;
SDL_Texture *texture4;
SDL_Texture *texture5;

SDL_DestroyTexture(texture);
texture = NULL;
SDL_DestroyTexture(texture1);
texture1 = NULL;
SDL_DestroyTexture(texture2);
texture2 = NULL;
SDL_DestroyTexture(texture3);
texture3 = NULL;
SDL_DestroyTexture(texture4);
texture4 = NULL;
SDL_DestroyTexture(texture5);
texture5 = NULL;
}

int main(int argc, char *argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);



    SDL_Texture* background = loadTexture("backg.png", renderer);

    SDL_Texture* gameover = loadTexture("gameover.jpg", renderer);

    SDL_Texture* background1 = loadTexture("backg1.png", renderer);

    SDL_Texture* water = loadTexture("dz.png", renderer);

    SDL_Texture* da = loadTexture("da.png", renderer);

    SDL_Texture* bird = loadTexture("bird.png", renderer);

    SDL_Texture* baseball = loadTexture("baseball.png", renderer);

    SDL_Texture* charecter1 = loadTexture("linh1.png", renderer);

    SDL_Texture* charecter2 = loadTexture("linh2.png", renderer);

    SDL_Texture* charecter3 = loadTexture("linh3.png", renderer);

    SDL_Texture* mong = loadTexture("mong.png", renderer);

    SDL_Texture* nhay = loadTexture("nhay.png", renderer);

    int e = 0;
    int r = 0;
    int u = 1000;
    int i = 0;

    renderTexture2(background, e, r, renderer);


   // SDL_RenderCopy( renderer, background, NULL, NULL);


    SDL_RenderPresent( renderer );


    waitUntilKeyPressed();

// tốc độ di chuyển

   int z = 8 ;

// tọa độ nhân vật

   int b = 330;

   int a = 80;

// tọa độ nước

   int x = 1000;

   int y = 310;

// tọa độ chim

   int s = 1000;

   int d = 300;

// tọa độ đá

   int f = 1000;
   int g = 430;

// tọa độ bóng

   int o = 1000;

   int p = 300;

// vat dau tien xuat hien

   int k = 0;

// ảnh xuất hiện

   int m = 0 ;

   int v = 0;

    while(true){

            SDL_Delay(10);

     //   SDL_RenderCopy( renderer, background, NULL, NULL);

      renderTexture2(background, e, r, renderer);

      renderTexture2(background1, u, i, renderer);


      if(m < 100){renderTexture3(charecter1, a, b, renderer);}
      if(m >= 100 && m < 200){renderTexture3(charecter2, a, b, renderer);}
      if(m >= 200 && m <= 300){renderTexture3(charecter3, a, b, renderer);}


        if((a+100) >= (x) && (a) <= (x+80)){cout << timeSinceEpochMillisec(); exit(1);}

        if((a+100) >= (f) && (a) <= (f+150)){cout << timeSinceEpochMillisec(); exit(1);}

        if((a+100) >= (s) && (a) <= (s-20)){cout << timeSinceEpochMillisec(); exit(1);}

        if((a+100) >= (o) && (a) <= (o-20)){cout << timeSinceEpochMillisec(); exit(1);}

        v = v + 1;
        if(v == 500){z=12;}
        if(v == 1000){z=16;}
        if(v == 1500){z=20;}
        if(v == 2000){z=24;}

        e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}



    switch(k){
    case(0):{renderTexture(water, x, y, renderer);
        x = x - z;
        if (x < 0){
            x = 1000;
        if(x == 1000){k = randomfence();}
}
break;
}

    case(1):{renderTexture1(bird, s, d, renderer);
        s = s - z;
        if (s < 0){
            s = 1000;
        if(s == 1000){k = randomfence();}
}
break;
}

    case(2):{renderTexture5(da, f, g, renderer);
        f = f - z;
        if (f < 0){
            f = 1000;
        if(f == 1000){k = randomfence();}
}
break;
}
      case(3):{renderTexture1(baseball, o, p, renderer);
        o = o - z;
        if (o < 0){
            o = 1000;
        if(o == 1000){k = randomfence();}
}
break;
}

        default:

         break;

        }

        SDL_RenderPresent( renderer );



        switch (getUserInput()){

       case(2):{

            while(b  <= 330 && b > 210){

                SDL_Delay(10);

                b = b - 4;

       // SDL_RenderCopy( renderer, background, NULL, NULL);
          renderTexture2(background, e, r, renderer);
          renderTexture2(background1, u, i, renderer);
          e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}

        renderTexture3(nhay, a, b, renderer);


        switch(k){

        case(0):{renderTexture(water, x, y, renderer);

         x = x - z;
        if (x < 0){
            x = 1000;

            if(x == 1000){k = randomfence();}

        }

                              break;
                                                       }

        case(1):{renderTexture1(bird, s, d, renderer);

         s = s - z;
        if (s < 0){
            s = 1000;

            if(s == 1000){k = randomfence();}

        }

                              break;

                                                 }

        case(2):{renderTexture5(da, f, g, renderer);

         f = f - z;
        if (f < 0){
            f = 1000;

            if(f == 1000){k = randomfence();}

        }

                              break;

                                                 }

        case(3):{renderTexture1(baseball, o, p, renderer);

         o = o - z;
        if (o < 0){
            o = 1000;

            if(o == 1000){k = randomfence();}

        }

                              break;

                                                 }

        default:

         break;

        }


        SDL_RenderPresent( renderer );



    }

            while(b >= 210 && b < 330){

                SDL_Delay(10);

                b = b + 4;

      //  SDL_RenderCopy( renderer, background, NULL, NULL);
         renderTexture2(background, e, r, renderer);
         renderTexture2(background1, u, i, renderer);
         e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}

        renderTexture3(nhay, a, b, renderer);


        switch(k){

        case(0):{renderTexture(water, x, y, renderer);

         x = x - z;
        if (x < 0){
            x = 1000;

            if(x == 1000){k = randomfence();}

        }

                              break;
                                                       }

        case(1):{renderTexture1(bird, s, d, renderer);

         s = s - z;
        if (s < 0){
            s = 1000;

            if(s == 1000){k = randomfence();}

        }

                              break;

                                                 }

        case(2):{renderTexture5(da, f, g, renderer);

        f = f - z;
        if (f < 0){
            f = 1000;

            if(f == 1000){k = randomfence();}

        }

                              break;

                                                 }

        case(3):{renderTexture1(baseball, o, p, renderer);

        o = o - z;
        if (o < 0){
            o = 1000;

            if(o == 1000){k = randomfence();}

        }


                              break;

                                                 }

        default:

         break;

        }


        SDL_RenderPresent( renderer );


     }

   break;

}

       case(3):{

            int step1 = a - 60;

            while (a > step1){

        SDL_Delay(10);

        a = a - 4;

       // SDL_RenderCopy( renderer, background, NULL, NULL);
         renderTexture2(background, e, r, renderer);
         renderTexture2(background1, u, i, renderer);
         e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}

        if(m < 100){renderTexture3(charecter1, a, b, renderer);}
      if(m >= 100 && m < 200){renderTexture3(charecter2, a, b, renderer);}
      if(m >= 200 && m <= 300){renderTexture3(charecter3, a, b, renderer);}

       m = m + 5;

    if(m > 300){m = 0;}


        switch(k){

        case(0):{renderTexture(water, x, y, renderer);

        x = x - z;
        if (x < 0){
            x = 1000;

            if(x == 1000){k = randomfence();}

        }


                              break;
                                                       }

        case(1):{renderTexture1(bird, s, d, renderer);

        s = s - z;
        if (s < 0){
            s = 1000;

            if(s == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(2):{renderTexture5(da, f, g, renderer);

        f = f - z;
        if (f < 0){
            f = 1000;

            if(f == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(3):{renderTexture1(baseball, o, p, renderer);

        o = o - z;
        if (o < 0){
            o = 1000;

            if(o == 1000){k = randomfence();}

        }


                              break;

                                                 }

        default:

         break;

        }


        SDL_RenderPresent( renderer );

        if(a <= 0){a = 1000; step1 = 940;}


    }

   break;

   }

    case(4):{

    int step = a + 60;

     while(a < step ){

        SDL_Delay(10);

        a = a + 4;

       // SDL_RenderCopy( renderer, background, NULL, NULL);
         renderTexture2(background, e, r, renderer);
         renderTexture2(background1, u, i, renderer);
         e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}

        if(m < 100){renderTexture3(charecter1, a, b, renderer);}
      if(m >= 100 && m < 200){renderTexture3(charecter2, a, b, renderer);}
      if(m >= 200 && m <= 300){renderTexture3(charecter3, a, b, renderer);}

       m = m + 5;

    if(m > 300){m = 0;}


        switch(k){

        case(0):{renderTexture(water, x, y, renderer);

        x = x - z;
        if (x < 0){
            x = 1000;

            if(x == 1000){k = randomfence();}

        }


                              break;
                                                       }

        case(1):{renderTexture1(bird, s, d, renderer);

        s = s - z;
        if (s < 0){
            s = 1000;

            if(s == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(2):{renderTexture5(da, f, g, renderer);

        f = f - z;
        if (f < 0){
            f = 1000;

            if(f == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(3):{renderTexture1(baseball, o, p, renderer);

        o = o - z;
        if (o < 0){
            o = 1000;

            if(o == 1000){k = randomfence();}

        }


                              break;

                                                 }

        default:

         break;

        }


        SDL_RenderPresent( renderer );


        if(a >= 1000) {a = 0; step = 60;}


    }

    break;

   }

   case(5):{

            while(b  >= 330 && b < 390){

                SDL_Delay(10);

                b = b + 4;

       // SDL_RenderCopy( renderer, background, NULL, NULL);
         renderTexture2(background, e, r, renderer);
         renderTexture2(background1, u, i, renderer);
         e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}

        renderTexture4(mong, a, 360, renderer);


        switch(k){

        case(0):{renderTexture(water, x, y, renderer);

        x = x - z;
        if (x < 0){
            x = 1000;

            if(x == 1000){k = randomfence();}

        }


                              break;
                                                       }

        case(1):{renderTexture1(bird, s, d, renderer);

        s = s - z;
        if (s < 0){
            s = 1000;

            if(s == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(2):{renderTexture5(da, f, g, renderer);

        f = f - z;
        if (f < 0){
            f = 1000;

            if(f == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(3):{renderTexture1(baseball, o, p, renderer);

        o = o - z;
        if (o < 0){
            o = 1000;

            if(o == 1000){k = randomfence();}

        }


                              break;

                                                 }

        default:

         break;

        }


        SDL_RenderPresent( renderer );


    }

            while(b <= 390 && b > 330){

                SDL_Delay(10);

                b = b - 4;

       // SDL_RenderCopy( renderer, background, NULL, NULL);
        renderTexture2(background, e, r, renderer);
        renderTexture2(background1, u, i, renderer);
        e = e - 2;
        if(e == -1000){e = 1000; renderTexture2(background, e, r, renderer);}
        u = u - 2;
        if(u == -1000){u = 1000; renderTexture2(background1, u, i, renderer);}

        renderTexture4(mong, a, 360, renderer);


        switch(k){

        case(0):{renderTexture(water, x, y, renderer);

        x = x - z;
        if (x < 0){
            x = 1000;

            if(x == 1000){k = randomfence();}

        }


                              break;
                                                       }

        case(1):{renderTexture1(bird, s, d, renderer);

        s = s - z;
        if (s < 0){
            s = 1000;

            if(s == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(2):{renderTexture5(da, f, g, renderer);

        f = f - z;
        if (f < 0){
            f = 1000;

            if(f == 1000){k = randomfence();}

        }


                              break;

                                                 }

        case(3):{renderTexture1(baseball, o, p, renderer);

        o = o - z;
        if (o < 0){
            o = 1000;

            if(o == 1000){k = randomfence();}

        }


                              break;

                                                 }

        default:

         break;

        }


        SDL_RenderPresent( renderer );


  }

   break;

}

    default:

    break;

  }

    getUserInput();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

    SDL_RenderClear(renderer);

    m = m + 5;

    if(m > 300){m = 0;}

    destroy();


    }

    waitUntilKeyPressed();

   destroy();

   SDL_DestroyTexture( background );
    background = NULL;

   SDL_DestroyTexture( background1 );
    background = NULL;


    quitSDL(window, renderer);


   return 0;
}
