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
        vids[i].initMode(BG0_BG1); //set video buffer to more BG0
        vids[i].attach(i); //attach video buffer to cube with ID `i`

        vids[i].bg0.image(vec(0,0), MyBG0Image); //Set the image `Background` defined in assets.lua to the VideoBuffer's BG0 layer

        /*
            MyBG1Image is 64x64 pixels which is 8x8 tiles.
            Placing its left corner at 4,4 will put it at the center of the screen.
            We mask the space then we place the image.
        */
            
        vids[i].bg1.setMask(BG1Mask::filled(vec(4,4), vec(8,8))); //Mask an area in the location and size of our BG1 image
        vids[i].bg1.image(vec(4,4), MyBG1Image); //Place a BG1 image in the same space as the mask. 
    }

    while (1) { //game looop
        System::paint();
    }
}
