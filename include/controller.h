#pragma once

class Controller {
public:
    virtual short getMoveDirection() = 0;
    virtual void setBounds(short* minY, short* maxY, short* paddleY) = 0;
    virtual ~Controller() = default;
};