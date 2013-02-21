/*
 * Using BG0
 */

#include <sifteo.h>
#include "assets.gen.h"
using namespace Sifteo;

static AssetSlot MainSlot = AssetSlot::allocate() //our assets
    .bootstrap(GameAssets);

static Metadata M = Metadata() //The metadata for the launcher
    .title("BG0 SDK Example")
    .package("com.sifteo.sdk.bg0", "1.0")
    .icon(Icon)
    .cubeRange(1);

void main()
{
    static VideoBuffer vid; //create video buffer

    vid.initMode(BG0); //set video buffer to BG0 mode
    vid.attach(0); //attach video buffer to cube with ID 0

    vid.bg0.image(vec(0,0), MyBG0Image); //Set the BG0 layer to the image `MyBG0Image` defined in assets.lua

    while (1) { //game looop
        System::paint();
    }
}
