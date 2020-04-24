#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enigmeh.h"

void init_enigme(enigme * e)
{
	e= ( p.x=0, p.y=0, img=NULL);
}

 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	int test=*alea ;
do
{
 *alea = 1+ rand()%6;
}
while(*alea==test) ;
 sprintf(image ,"%d.png",*alea);
e->img = IMG_Load(image);
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
  SDL_Flip(screen) ;
}
 
 int solution_e (char image [],int *ques)
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"1.png")==0)
 	{
     solution =3 ;
 	(*ques)=1;
}
 	else  	if(strcmp(image,"2.png")==0)
 	{
 		solution =2;
		(*ques)=2;

 	}
 	else 	if(strcmp(image,"3.png")==0)
 	{
 		solution =1;
(*ques)=3;	
 	}
 	else 	if(strcmp(image,"4.png")==0)
 	{
 		solution =2;
(*ques)=4;	
 	}
 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;
  int r=0 ;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_z:
			   r= 2;
			   break;
			   case SDLK_e: 
			   r=3 ;
			   break;
			    }
       break ;

                 
	}
  return r ;
}

void afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en,int ques)
 {
SDL_Surface * image=NULL;
 switch(ques)
{
case 1:
image=IMG_Load("1e.png");
break;

case 2:
image=IMG_Load("2e.png");
break;

case 3:
image=IMG_Load("3e.png");
break;

case 4:
image=IMG_Load("4e.png");
break;

	SDL_BlitSurface(image, NULL, screen, &(en=p)) ;
        SDL_Flip(screen);
 	if (r==s)
 	{
	en_img=IMG_Load("00.jpg"); // image de : vous avez repondu correctement
 		SDL_BlitSurface(en=img, NULL, screen, &(en_p)) ;
        SDL_Flip(screen);
 		} 	
 	else
 	{
 		en_img=IMG_Load("11.jpg"); // image de : vous avez répondu faux
 		SDL_BlitSurface(en=img, NULL, screen, &(en_p)) ;
        SDL_Flip(screen);
 	}
 }
