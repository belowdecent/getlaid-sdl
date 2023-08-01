#include <SDL.h>

static inline int init_error(const char* message_fmt) {
  SDL_LogError(
    SDL_LOG_CATEGORY_APPLICATION, message_fmt,
    SDL_GetError()
  );
  return 1;
}

int initialize(SDL_Window** win, SDL_Renderer** renderer) {
  if (SDL_Init(SDL_INIT_VIDEO))
    return init_error("Couldn't initialize SDL: %s");

  *win = SDL_CreateWindow(
    "Get laid example", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE
  );

  if (*win == NULL)
    return init_error("Couldn't create window: %s");

  *renderer =
    SDL_CreateRenderer(*win, -1, SDL_RENDERER_PRESENTVSYNC);

  if (*renderer == NULL) {
    return init_error("Couldn't create renderer: %s");
  }

  return 0;
}
