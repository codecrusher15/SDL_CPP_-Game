#include "ECS.hpp"

class PositionComponent : public Component
{
    private:
        int xpos, ypos;
    
    public:
        int getX()
        {
            return xpos;
        }

        int getY()
        {
            return ypos;
        }

        void init() override
        {
            xpos = 0;
            ypos = 0;
        }
        
        void setPos(int x, int y)
        {
            xpos = x;
            ypos = y;
        }

        void update() override
        {
            xpos++;
            ypos++;
        }
};