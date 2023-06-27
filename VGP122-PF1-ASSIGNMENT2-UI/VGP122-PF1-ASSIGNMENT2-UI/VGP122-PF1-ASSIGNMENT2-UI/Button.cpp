#include "Button.h"

Button::Button(std::string f, int x, int y, int w, int h, int rows, int cols) : Sprite(Game::getRenderer(), f, x, y, w, h, rows, cols)
{
    pressed = false;
    active = true; // Assuming the button is active by default
    setCurrentFrame(0);
}

void Button::update()
{
    Sprite::update();
}

void Button::render()
{
    Sprite::render();
}

void Button::onPress()
{
    if (active)
    {
        pressed = true;
        // Perform additional actions when the button is pressed and active
    }
}

void Button::onRelease()
{
    pressed = false;
}

bool Button::isPressed()
{
    return pressed;
}

void Button::setActive(bool isActive)
{
    active = isActive;
    // You can perform additional actions when the button's active state changes
}

bool Button::isActive()
{
    return active;
}
