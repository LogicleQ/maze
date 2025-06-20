#include "maze.hpp"

#include <stdexcept>

// custom operator overload to make it easier to manipulate float points
SDL_FPoint operator + (SDL_FPoint pt1, SDL_FPoint pt2)
{
	return SDL_FPoint
	{
		.x = pt1.x + pt2.x,
		.y = pt1.y + pt2.y
	};
}


// custom overload to make it easier to set the rendering color
bool SDL_SetRenderDrawColorFloat (SDL_Renderer* renderer, SDL_FColor color)
{
	return SDL_SetRenderDrawColorFloat(renderer, color.r, color.g, color.b, color.a);
}



// get the pixel position of a corner of a block
SDL_FPoint Maze::getBlockCornerPos (blockCorner corner, int blockX, int blockY)
{

	SDL_FPoint topLeft
	{
		.x = (float) m_padPixels + blockX * m_blockPixelSize,
		.y = (float) m_padPixels + blockY * m_blockPixelSize
	};


	switch (corner)
	{

		case TOP_LEFT:
			return topLeft;

		case TOP_RIGHT:
			return topLeft + SDL_FPoint{.x = (float) m_blockPixelSize, .y = 0};

		case BOTTOM_LEFT:
			return topLeft + SDL_FPoint{.x = 0, .y = (float) m_blockPixelSize};

		case BOTTOM_RIGHT:
			return topLeft + SDL_FPoint{.x = (float) m_blockPixelSize, .y = (float) m_blockPixelSize};

		default:
			throw std::runtime_error("invalid enum option, thrown from Maze::getBlockCornerPos");

	};

}

