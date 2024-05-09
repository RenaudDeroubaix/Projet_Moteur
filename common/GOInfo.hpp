#pragma once
#include "common/utils.hpp"

class GOInfo{
protected:
    //Par rapport au moteur phy
    bool moved_recently=false; 

    bool has_physics=true;
    bool is_movable=false;
    bool is_pickable=false;
        
    //Type de GO
    bool is_rendered=true;
    bool is_camera=false;
    bool is_event=false;
    bool is_falling=false;
    bool is_directional=false;
    
    
    
    
    
public:

    GOInfo() {}

    GOInfo(bool movedRecently, bool hasPhysics, bool isMovable, bool isPickable, bool isRendered, bool isCamera, bool isEvent) : 
        moved_recently(movedRecently),
        has_physics(hasPhysics),
        is_movable(isMovable),
        is_pickable(isPickable),
        is_rendered(isRendered),
        is_camera(isCamera),
        is_event(isEvent) {}

    ~GOInfo() {}

    void setMovedRecently(bool value) { moved_recently = value; }

    bool getMovedRecently() const { return moved_recently; }

    void setHasPhysics(bool value) { has_physics = value; }

    bool getHasPhysics() const { return has_physics; }

    void setIsMovable(bool value) { is_movable = value; }

    bool getIsMovable() const { return is_movable; }

    void setIsPickable(bool value) { is_pickable = value; }

    bool getIsPickable() const { return is_pickable; }

    void setIsRendered(bool value) {  is_rendered = value; }

    bool getIsRendered() const { return is_rendered; }

    void setIsCamera(bool value) { is_camera = value; }

    bool getIsCamera() const { return is_camera; }

    void setIsEvent(bool value) { is_event = value; }

    bool getIsEvent() const { return is_event; }
    
    void setIsFalling(bool value) { is_falling = value; }

    bool getIsFalling() const { return is_falling; }
    
    void setIsLightDirectional(bool value){is_directional = value;}
    
    bool getIsLightDirectional() const { return is_directional;}
};
