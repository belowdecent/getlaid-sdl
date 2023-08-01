#include <SDL.h>
#include <getlaid-sdl.h>

#include "../sdl_init.c"
#include "getlaid-padding.h"
#include "getlaid-units.h"

int main(void) {
  SDL_Window* win;
  SDL_Renderer* renderer;

  if (initialize(&win, &renderer)) {
    SDL_Quit();
    return 3;
  }

  GTLD_Element el = {
    .count = 3,
    .children = malloc(sizeof(GTLD_Element) * 3),
    .padding = GTLD_PADDING_ALL(GTLD_UNIT_PX, 10),
    .bounds = {.x = 10, .y = 10, .w = 500, .h = 128},
    .container = GTLD_AUTOCONTAINER(
      GTLD_ROW, GTLD_ALIGN_BEGIN, GTLD_ALIGN_CENTER
    )
  };

  el.children[0] = (GTLD_Element){0};
  el.children[1] = (GTLD_Element){0};
  el.children[2] = (GTLD_Element){0};

  GTLD_Rect* rect = GTLD_GetChildrenBounds(
    &el.container, GTLD_PadBounds(el.bounds, el.padding), 3
  );
  for (int i = 0; i < el.count; ++i) {
    el.children[i].bounds = rect[i];
  }
  free(rect);

  SDL_Event e;

  while (1) {
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
      break;
    }

    SDL_SetRenderDrawColor(
      renderer, 0xFF, 0xFF, 0xFF, 0xFF
    );
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(
      renderer, 0xFF, 0x00, 0x00, 0xFF
    );
    SDL_RenderFillRect(renderer, &el.bounds);

    SDL_SetRenderDrawColor(
      renderer, 0x00, 0xFF, 0x00, 0xFF
    );
    SDL_RenderFillRect(renderer, &el.children[0].bounds);

    SDL_SetRenderDrawColor(
      renderer, 0x00, 0x00, 0xFF, 0xFF
    );
    SDL_RenderFillRect(renderer, &el.children[1].bounds);

    SDL_SetRenderDrawColor(
      renderer, 0x00, 0xFF, 0xFF, 0xFF
    );
    SDL_RenderFillRect(renderer, &el.children[2].bounds);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
