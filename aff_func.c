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

void 					aff_hud(SDL_Surface *screen)
{
	SDL_Rect 			pos;
	SDL_Surface 		*hud[8];
	int 				i = 4;

	pos.x = 0;
	pos.y = 0;

	hud[0] = IMG_Load("img/texture/portrait.png");
	hud[1] = IMG_Load("img/texture/sake.png");
	hud[2] = IMG_Load("img/texture/sake_pow.png");
	hud[3] = IMG_Load("img/texture/sake_pow_end.png");
	hud[4] = IMG_Load("img/texture/life.png");
	hud[5] = IMG_Load("img/texture/life_pow.png");
	hud[6] = IMG_Load("img/texture/life_pow_end.png");
	hud[7] = IMG_Load("img/texture/inventaire.png");

	SDL_BlitSurface(hud[0], NULL, screen, &pos); // Affichage portrait
	
	pos.x = 80;
	pos.y = 40;

	SDL_BlitSurface(hud[1], NULL, screen, &pos); // Affichage sake

	pos.x = pos.x + 40;

	while (i >= 0)
	{
		SDL_BlitSurface(hud[2], NULL, screen, &pos);
		i--;
		pos.x = pos.x + 40;
	}
	SDL_BlitSurface(hud[3], NULL, screen, &pos);

	pos.x = 80;
	pos.y = 0;

	SDL_BlitSurface(hud[4], NULL, screen, &pos); // Affichage sake

	pos.x = pos.x + 40;
	i = 4;

	while (i >= 0)
	{
		SDL_BlitSurface(hud[5], NULL, screen, &pos);
		i--;
		pos.x = pos.x + 40;
	}
	SDL_BlitSurface(hud[6], NULL, screen, &pos);

	pos.x = 1040;

	SDL_BlitSurface(hud[7], NULL, screen, &pos);

	SDL_Flip(screen);
}