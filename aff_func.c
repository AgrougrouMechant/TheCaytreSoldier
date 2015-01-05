#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void 				aff_vietmouss(SDL_Surface *screen, SDL_Rect pos)
{
	SDL_Surface 	*viet;

	viet = IMG_Load("img/character.png");
	SDL_BlitSurface(viet, NULL, screen, &pos);
	SDL_Flip(screen);
}

void 				aff_level(SDL_Surface *screen, int map[])
{
	SDL_Surface 	*texture[4];
	SDL_Rect		pos;
	int 			i = 0;

	pos.x = 0;
	pos.y = 0;

	// Chargement Texture
	texture[0] = IMG_Load("img/texture/0.png");
	texture[1] = IMG_Load("img/texture/1.png");
	texture[2] = IMG_Load("img/texture/2.png");
	texture[3] = IMG_Load("img/texture/3.png");

	// Fin chargement texture

	// Debut du remplissage 
	while (pos.y < 720)
	{
		while (pos.x < 1280)
		{
			SDL_BlitSurface(texture[map[i]], NULL, screen, &pos);
			pos.x = pos.x + 40;
			SDL_Flip(screen);
			i++;
		}
		pos.x = 0;
		pos.y = pos.y + 40;
	}

	// Fin du remplissage


	SDL_FreeSurface(texture[0]);
	SDL_FreeSurface(texture[1]);
	SDL_FreeSurface(texture[2]);
	SDL_FreeSurface(texture[3]);
	//
}

void 		aff_grille(SDL_Surface *screen)
{
	SDL_Surface 	*grille;
	SDL_Rect 		pos;

	grille = IMG_Load("img/texture/grille.png");
	pos.x = 0;
	pos.y = 0;
	SDL_BlitSurface(grille, NULL, screen, &pos);
	SDL_Flip(screen);
}