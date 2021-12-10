#include<iostream>
#include<vector>
#include<array>
#include<bitset>
#include<memory>

class Component;
class Entity;

using ComponentId = std::size_t;        //If system is 32 bits, then int is of 32 bits and if it is of 64, then int will be of 64 bits...

inline ComponentId getComponentId()
{
    static ComponentId lastId = 0;
    return lastId++;
}

template <typename T>
inline ComponentId getComponentId() noexcept
{
    static ComponentId typeId = getComponentId();
    return typeId;
}

class Component
{
    public:
        Entity *entity;
        virtual void init() {;}
        virtual void update() {;}
        virtual void draw() {;}
        virtual ~Component() {;}
};

using ComponentBitSet =  std::bitset<32UL>;
using ComponentArray = std::array<Component*, 32UL>;
class Entity
{
    private:
        bool active = true;
        std::vector<Component *> components;     //Collection of objects of class Component...
        ComponentArray componentArray;
        ComponentBitSet componentBitSet;

    public:
        void update()
        {
            for(auto &comp : components)
                comp->update();
        }

        void draw()
        {
            for(auto &comp : components)
                comp->draw();
        }
        
        bool isActive()
        {
            return active;
        }

        void destroy()
        {
            active = false;
        }

        template <typename T>
        bool hasComponent()
        {
            return componentBitSet[getComponentId<T>];
        }

        template <typename T, typename... TArgs>
        T &addComponent(TArgs&&... mArgs)
        {
            T *c(new T(std::forward<TArgs>(mArgs)...));
            c->entity = this;
            components.push_back(c);
            componentArray[getComponentId<T>()] = c;
            componentBitSet[getComponentId<T>()] = true;
            c->init();
            return *c;
        }

        template <typename T>
        T &getComponent()
        {
            auto ptr(componentArray[getComponentId<T>()]);
            return *static_cast<T*>(ptr);
        }
};

class Manager
{
    private:
        std::vector<Entity*> entities;

    public:
        void update()
        {
            for(auto &entity : entities)
                entity->update();
        }
        void draw()
        {
            for(auto &entity : entities)
                entity->draw();
        }
        
        Entity *addEntity()
        {
            Entity *entity = new Entity();
            entities.push_back(entity);
            return entity;
        }
};