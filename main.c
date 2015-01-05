#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
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
	SDL_Delay(120);
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

int			main(int ac, char **av)
{
	SDL_Surface		*screen;
	SDL_Rect		pos;

	pos.x = 160;
	pos.y = 440;

	SDL_Init(SDL_INIT_EVERYTHING); // Initialisation SDL

	screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // Création du BG
	SDL_WM_SetCaption("The Caytre Soldier", NULL);
	aff_level(screen, fill_map("Level/Level1/slide1.txt"));
	aff_vietmouss(screen, pos);
	aff_grille(screen);
	aff_hud(screen);
	pause();

	SDL_Quit();

}