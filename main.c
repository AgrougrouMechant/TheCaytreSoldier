#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "include/func.h"
#include <sys/stat.h> 
#include <fcntl.h>

void 		pause()
{
    int 	continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}


int 		*fill_map(char *path)
{
	int 	*map;
	char 	buffer[2056];
	int 	fd;
	int 	i;
	int 	index;

	i = 0;
	index = 0;
	map = malloc(sizeof(int) * 2056);
	fd = open(path, O_RDONLY);
	read(fd, buffer, 2056);
	close(fd);
	buffer[2055] = '\0';
	while (buffer[i] != '\0')
	{
		if (buffer[i] != ' ' && buffer[i] != '\n')
		{
			map[index] = buffer[i] - 48;
			index++;
		}
		i++;
	}

	return (map);
}

void 		load_new_game(SDL_Surface *screen)
{
	SDL_Rect pos;

	pos.x = 160;
	pos.y = 440;

	aff_level(screen, fill_map("Level/Level1/slide1.txt"));
	aff_vietmouss(screen, pos);
	aff_grille(screen);
	aff_hud(screen);
}

void 		load_start_screen(SDL_Surface *screen)
{
	//Déclaration des surfaces
	SDL_Surface 	*bg, *b0, *b1, *b2, *b3, *b4, *b5, *b6;

	//Déclaration des position
	SDL_Rect		posBg;
	SDL_Rect		posTitle;
	SDL_Rect		posNewG;
	SDL_Rect		posLoadG;
	SDL_Rect		posLeave;

	//Déclaration des police
	TTF_Font 		*title;
	TTF_Font 		*menu;

	//Déclaration des events
	SDL_Event 		event;

	//Déclaration de variable tierce
	int 			choice = 0;
	int 			i = 1;

	//Déclaration et initialisation des couleurs
	SDL_Color 		black = {0, 0, 0};
	SDL_Color 		yellow = {255, 220, 0}; // 255 246 13
	SDL_Color		selected = {255, 0, 0};

	//Chargement des polices
	title = TTF_OpenFont("font/martyric.ttf", 72);
	menu = TTF_OpenFont("font/chinesetakeaway.ttf", 48);

	//Chargement des surfaces
	bg = IMG_Load("img/texture/bg_start_menu.png");
	b0 = TTF_RenderText_Blended(title, "The Caytre Soldier", black);
	b1 = TTF_RenderText_Blended(menu, "Nouvelle partie", yellow);
	b2 = TTF_RenderText_Blended(menu, "Charger une partie", yellow);
	b3 = TTF_RenderText_Blended(menu, "Quitter", yellow);
	b4 = TTF_RenderText_Blended(menu, "Nouvelle partie", selected);
	b5 = TTF_RenderText_Blended(menu, "Charger une partie", selected);
	b6 = TTF_RenderText_Blended(menu, "Quitter", selected);

	//Initialisation des positions
	posBg.x = 0;
	posBg.y = 0;
	//-- Titre
	posTitle.x = (1280 / 2) - (b0->w / 2);
	posTitle.y = 40;
	//-- Nouvelle partie
	posNewG.x = (1280 / 2) - (b1->w / 2);
	posNewG.y = posTitle.y + b0->h + 100;
	//-- Charger une partie
	posLoadG.x = (1280 / 2) - (b2->w / 2);
	posLoadG.y = posNewG.y + b1->h + 40;
	//-- Quitter
	posLeave.x = (1280 / 2) - (b3->w / 2);
	posLeave.y = posLoadG.y + b2->h + 40;


	//----------- Collage des surfaces
	SDL_BlitSurface(bg, NULL, screen, &posBg);
	SDL_BlitSurface(b0, NULL, screen, &posTitle);
	SDL_BlitSurface(b4, NULL, screen, &posNewG);
	SDL_BlitSurface(b2, NULL, screen, &posLoadG);
	SDL_BlitSurface(b3, NULL, screen, &posLeave);
	
	//Début event
	while (choice != 1)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						switch(i)
						{
							case 1:
								i = 3;
								SDL_BlitSurface(b6, NULL, screen, &posLeave);
								SDL_BlitSurface(b1, NULL, screen, &posNewG);
								break;
							case 2:
								i = 1;
								SDL_BlitSurface(b4, NULL, screen, &posNewG);
								SDL_BlitSurface(b2, NULL, screen, &posLoadG);
								break;
							case 3:
								i = 2;
								SDL_BlitSurface(b5, NULL, screen, &posLoadG);
								SDL_BlitSurface(b3, NULL, screen, &posLeave);
								break;
						}
						break;
					case SDLK_DOWN:
						switch(i)
						{
							case 1:
								i = 2;
								SDL_BlitSurface(b5, NULL, screen, &posLoadG);
								SDL_BlitSurface(b1, NULL, screen, &posNewG);
								break;
							case 2:
								i = 3;
								SDL_BlitSurface(b6, NULL, screen, &posLeave);
								SDL_BlitSurface(b2, NULL, screen, &posLoadG);
								break;
							case 3:
								i = 1;
								SDL_BlitSurface(b4, NULL, screen, &posNewG);
								SDL_BlitSurface(b3, NULL, screen, &posLeave);
								break;
						}
						break;
					case SDLK_RETURN:
						choice = 1;
						break;
				}
		}
		SDL_Flip(screen);
	}

	switch (i)
	{
		case 1:
			load_new_game(screen);
			break;
		case 2:
			break;
		case 3:
			exit;
			break;
	}
	//Fermeture des polices
	TTF_CloseFont(title);
	TTF_CloseFont(menu);
}



int			main(int ac, char **av)
{
	SDL_Surface		*screen;
	SDL_Rect		pos;

	pos.x = 160;
	pos.y = 440;

	SDL_Init(SDL_INIT_EVERYTHING); // Initialisation SDL
	TTF_Init(); // Initialisation SDL_TTF

	screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // Création du BG
	SDL_WM_SetCaption("The Caytre Soldier", NULL);
	load_start_screen(screen);
	pause();


	TTF_Quit();
	SDL_Quit();

}