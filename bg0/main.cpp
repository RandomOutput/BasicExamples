/*
 * Using BG0
 */

#include <sifteo.h>
#include "assets.gen.h"
using namespace Sifteo;

static const unsigned gNumCubes = 3; //number of cubes we'll be using

static AssetSlot MainSlot = AssetSlot::allocate() //our assets
    .bootstrap(GameAssets);

static Metadata M = Metadata() //The metadata for the launcher
    .title("Stars SDK Example")
    .package("com.sifteo.sdk.stars", "1.0")
    .icon(Icon)
    .cubeRange(gNumCubes);

void main()
{
    static VideoBuffer vids[gNumCubes]; //create video buffers for each cube

    for (unsigned i = 0; i < arraysize(vids); i++)
    {
        vids[i].initMode(BG0); //set video buffer to BG0 mode
        vids[i].attach(i); //attach video buffer to cube with ID `i`

        vids[i].bg0.image(vec(0,0), MyBG0Image); //Set the image `Background` defined in assets.lua to the VideoBuffer's BG0 layer
    }

    while (1) { //game looop
        System::paint();
    }
}
