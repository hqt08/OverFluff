#include "MapTile.h"

float AMapTileActor::GetMapTileDilation()
{
	if (Data)
	{
		return Data->DilationFactor;
	}

	return 1.0f;
}
