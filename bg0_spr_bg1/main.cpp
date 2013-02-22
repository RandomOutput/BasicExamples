/*
 * BG0_SPR_BG1 Demo
 */

#include <sifteo.h>
#include "assets.gen.h"
using namespace Sifteo;

static AssetSlot MainSlot = AssetSlot::allocate() //our assets
    .bootstrap(GameAssets);

static Metadata M = Metadata() //The metadata for the launcher
    .title("BG0_SPR_BG1 Demo")
    .package("com.sifteo.sdk.bg0sprbg1", "1.0")
    .icon(Icon)
    .cubeRange(1);

void main()
{
    //SETUP VIDEO BUFFER
    static VideoBuffer vid; //create video buffer for each cube
    vid.initMode(BG0_SPR_BG1); //set video buffer to BG0_SPR_BG1 mode
    vid.attach(0); //attach video buffer to cube with ID 0

    //BACKGROUND LAYER
    vid.bg0.image(vec(0,0), MyBG0Image); //Set the image `Background` defined in assets.lua to the VideoBuffer's BG0 layer

    //SPRITES LAYER
    vid.sprites[0].setImage(MyRedSprite); //assign our first sprite
    vid.sprites[0].move(15,15); //move it to where we want it

    vid.sprites[1].setImage(MyBlueSprite);
    vid.sprites[1].move(93, 60); 

    //FOREGROUND LAYER
    vid.bg1.setMask(BG1Mask::filled(vec(4,4), vec(8,8))); //Mask an area in the location and size of our BG1 image
    vid.bg1.image(vec(4,4), MyBG1Image); //Place a BG1 image in the same space as the mask. 

    while (1) { //game looop
        System::paint();
    }
}
