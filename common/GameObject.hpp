#pragma once
#include "common/utils.hpp"
#include "common/Renderer.hpp"
#include "common/Event.hpp"
#include "common/GOInfo.hpp"

struct ChampVision 
{
    
    glm::vec3 origin;
    glm::vec3 direction;
    float r;
    float h;
    float r_sol;
    
    ChampVision(){}
    
    ChampVision(glm::vec3 A , glm::vec3 B , float rayon , float hauteur , float rayon_sol)
    {
        origin = A;
        direction = B;
        r = rayon;
        h = hauteur;
        r_sol = rayon_sol;
    }
    ~ChampVision(){}
};


class GameObject {
public:
    bool is_camera = false;
    bool is_rendered = false;
protected:
   
    
    float object_speed = 1.;
    glm::vec3 up = glm::vec3(0,1,0);
    glm::vec3 right = glm::vec3(1,0,0);
    glm::vec3 front = glm::vec3(0,0,1);
    
    
    glm::vec3 minBoundingBox;
    glm::vec3 maxBoundingBox;

    std::vector<glm::vec3> position;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> tex_coords;
    std::vector<unsigned short> indices;
    
    glm::vec3 pos = glm::vec3(0.f);
    glm::vec3 color = glm::vec3();
    glm::vec3 vitesse = glm::vec3(0.f);
    float masse=0.0;
    
    glm::mat4 modelmat;
    glm::quat rotation;
    
    Renderer renderer;
    GOInfo gameObjectInfo = GOInfo();
    Event event;
    ChampVision champ_de_vision;
    
public:
    GameObject(){}
    GameObject(glm::vec3 p) : pos(p) {}

    void calculateBoundingBox() ;
    bool checkCollision(const GameObject& other);
    
    glm::vec3 getMaxBB(){return maxBoundingBox;}
    glm::vec3 getMinBB(){return minBoundingBox;}
    
    GLuint getprogID() const {return renderer.programID;}
    
    virtual ~GameObject() = default;
    
    virtual void initobject() = 0;
    virtual void drawobject() = 0;
    virtual void deleteobject() = 0;
    virtual void settexture(const std::string & path , GLuint textureIndex, const std::string & name_in_shader) = 0; 
    virtual void loadtextures() = 0;
    
    void set_speed(float f) {object_speed = f;}
    float get_speed(){return object_speed;}
    
    glm::vec3 get_up(){return up;}
    glm::vec3 get_right(){return right;}
    glm::vec3 get_front(){return front;}

    void set_front(glm::vec3 f)
    {
        front = f;
        right = glm::cross(front , glm::vec3(0,1,0));
        up = glm::cross(right , front);
    }

    void set_pos(glm::vec3 p){modelmat[3][0] = p[0]; modelmat[3][1] = p[1]; modelmat[3][2] = p[2];}
    void set_color(glm::vec3 c){color = c;}
    float getscale(){return modelmat[1][1]; }
    glm::vec3 getcolor(){return color;}
    glm::vec3 getpos();
    glm::mat4 getmodelmat();
    
    void setmodelmat(glm::mat4 m){modelmat = m;}

    void setpos(glm::vec3 p);
    void setscale(glm::vec3 s);
    void settranslate(glm::vec3 t);
    void setrotate(float angle , glm::vec3 axe);
    void rotateeulerYaw(glm::vec3 euler);

    void setgameObjectInfo(GOInfo goi){ gameObjectInfo = goi; }
    GOInfo& getgameObjectInfo(){ return gameObjectInfo ;}

    void setEvent(Event ev){
        event=ev;
    }
    Event getEvent(){return event;}

    glm::vec3 getVitesse(){return vitesse;}
    void update_champ_de_vision(){
        champ_de_vision = ChampVision(getpos() , get_front() ,champ_de_vision.r , champ_de_vision.h ,champ_de_vision.r_sol  );
    }
    void setChampVision(ChampVision CV){
        champ_de_vision = CV;
    }
    void setVitesse(glm::vec3 d){
        vitesse = d;
        for (int i=0; i<3; i++){
            vitesse[i] > 0.02? vitesse[i] = 0.02 : vitesse[i] < -0.02? vitesse[i] = -0.02: vitesse[i];
        }
    }
    void addVitesse(glm::vec3 d){
        vitesse+=d; 
          
     }
    void reduceVitesse(float ps){
        for (int i=0; i<3; i++){
            vitesse[i] < -ps*4 ? vitesse[i] += ps*4 : vitesse[i] > ps*4 ? vitesse[i] -= ps*4 : vitesse[i] = 0;
        }
    }
    float getMasse(){return masse;}
    void setMasse(float m){masse = m;}

    
    // void is_on_object(GameObject * go){
    //     glm::vec4 A; glm::vec3 AB;
    //     glm::vec4 B; glm::vec3 AC;
    //     glm::vec4 C; glm::vec3 AP;
    //     glm::vec3 P = this->getpos();
    
    //     for(int i = 0 ; i< indices.size() ; i+=3){
    //         // je recupere les 3 pts du triangle.
    //         A = getmodelmat() * glm::vec4 (positions[indices[i]]   , 1.f) ;
    //         B = getmodelmat() * glm::vec4 (positions[indices[i+1]] , 1.f) ;
    //         C = getmodelmat() * glm::vec4 (positions[indices[i+2]] , 1.f) ;
    //         /////////////////////////////////////////////
    //         //je calcule les coord barycentrique pour savoir si l'objet est dans un des triangles en x et z.
    //         float detABM = glm::determinant(glm::mat3  (A.x , 1.f , A.z , 
    //                                                     B.x , 1.f , B.z ,
    //                                                     P.x , 1.f , P.z ));
            
    //         float detAMC = glm::determinant(glm::mat3  (A.x , 1.f , A.z , 
    //                                                     P.x , 1.f , P.z ,
    //                                                     C.x , 1.f , C.z ));
            
    //         float detMBC = glm::determinant(glm::mat3  (P.x , 1.f , P.z , 
    //                                                     B.x , 1.f , B.z ,
    //                                                     C.x , 1.f , C.z ));
            
    //         if (detABM >= 0 and detAMC >= 0 and detMBC >= 0){
    //             // lorsque les Trois det sont >= 0 je suis dans un triangle sur la coord x et z
    //             AB = glm::vec3(A.x,A.y,A.z) - glm::vec3(B.x,B.y,B.z) ;
    //             AC = glm::vec3(A.x,A.y,A.z) - glm::vec3(C.x,C.y,C.z) ;
    //             AP = glm::vec3(A.x,A.y,A.z) - P ;
    //             //Calcule le det de la matrice (AB AC AP) on retrouve ou la capsule doit etre en y avec det(AB AC AP) = 0 + un offset. 
    //             float y = (((AB.x * AC.y * AP.z) + (AB.y * AP.x * AC.z) - (AP.x * AC.y * AB.z) - (AP.z * AC.x * AB.y)) / -((AC.z * AB.x) - (AC.x * AB.z))) + A.y
    //             this->getmodelmat()[1][3] = y + this->getmodelmat()[1][1] / 2.f ;
    //             break;
    //         }
    //     }
    // }
    /*
    bool in_champ_de_vision(GameObject* go)
    {
        bool is_point_inside_cone = false;
        for (glm::vec3 point : position){
            
            glm::vec4 P = modelmat * glm::vec4(point , 1.0f);
            glm::vec3 p = glm::vec3(P.x , P.y , P.z);
            
            float dist = glm::length(p - go->champ_de_vision.origin);
            if ((0 <= dist) and (dist <= go->champ_de_vision.h))
            {
                float cone_radius = (dist / go->champ_de_vision.h) * go->champ_de_vision.r;
                float orth_distance = glm::length((p - go->champ_de_vision.origin) - dist * go->champ_de_vision.direction);
                is_point_inside_cone = (orth_distance < cone_radius);
            }
            
            if (is_point_inside_cone) break;
        }
        return is_point_inside_cone;
    }*/
    bool in_champ_de_vision(GameObject* go)
    {
        bool is_point_inside_cylinder = false;
        for (glm::vec3 point : position)
        {
            glm::vec4 P = modelmat * glm::vec4(point, 1.0f);
            glm::vec3 p = glm::vec3(P.x, P.y, P.z);
            
            // Calcul de la distance entre le point et l'origine du cylindre
            glm::vec3 direction_to_point = p - go->champ_de_vision.origin;
            float dist_along_direction = glm::dot(direction_to_point, go->champ_de_vision.direction);
            glm::vec3 closest_point_on_axis = go->champ_de_vision.origin + dist_along_direction * go->champ_de_vision.direction;
            float dist_to_axis = glm::length(p - closest_point_on_axis);

            // Vérification si le point est à l'intérieur du cylindre
            if (dist_to_axis <= go->champ_de_vision.r && 0 <= dist_along_direction && dist_along_direction <= go->champ_de_vision.h)
            {
                is_point_inside_cylinder = true;
                break;
            }
        }
        return is_point_inside_cylinder;
    }

    void affichemodelmat(){
            std::cout<<"Model Matrix:"<< renderer.programID<<std::endl;
        for (int i = 0 ; i<4 ; i++){
            std::cout<<"\t"<<modelmat[0][i] << "\t" << modelmat[1][i] << "\t" << modelmat[2][i]<< "\t" << modelmat[3][i] << std::endl;
        }
    }
     void afficheDetail(){
            std::cout<<"Poses:"<< renderer.programID<<std::endl;
        for (unsigned short v : indices){
            std::cout<<"\t"<<v << "\t" << v << "\t" <<v << "\t" << std::endl;
        }
    }
};
