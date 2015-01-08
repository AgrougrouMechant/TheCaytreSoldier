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
	TTF_Font 		*title, *menu;

	//Déclaration
	SDL_Color 		black = {0, 0, 0};
	SDL_Color 		yellow = {255, 220, 0}; // 255 246 13
	SDL_Color		selected = {255, 246, 13};

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

	//


	//----------- DEBUT CODE DEGUEULASSE

	pos.x = 0;
	pos.y = 0;

	SDL_BlitSurface(bg, NULL, screen, &pos);

	pos.x = (1280 / 2) - (b0->w / 2);
	pos.y = 40;

	SDL_BlitSurface(b0, NULL, screen, &pos);

	pos.x = (1280 / 2) - (b1->w / 2);
	pos.y = pos.y + b0->h + 100;

	SDL_BlitSurface(b1, NULL, screen, &pos);

	pos.x = (1280 / 2) - (b2->w / 2);
	pos.y = pos.y + b1->h + 40;

	SDL_BlitSurface(b2, NULL, screen, &pos);

	pos.x = (1280 / 2) - (b3->w / 2);
	pos.y = pos.y + b2->h + 40;

	SDL_BlitSurface(b3, NULL, screen, &pos);

	// --------------------------------------


	SDL_Flip(screen);



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
/*	aff_level(screen, fill_map("Level/Level1/slide1.txt"));
	aff_vietmouss(screen, pos);
	aff_grille(screen);
	aff_hud(screen);*/
	load_start_screen(screen);
	pause();


	TTF_Quit();
	SDL_Quit();

}