#include "Mesh.hpp"

   // Post processing flags

bool Mesh::loadOFF( const std::string & filename)
{
    bool convertToTriangles = false;
    bool randomize = false;

    std::ifstream myfile;
    myfile.open(filename.c_str());
    if (!myfile.is_open())
    {
        std::cout << filename << " cannot be opened" << std::endl;
        return false;
    }

    std::string magic_s;

    myfile >> magic_s;

    if( magic_s != "OFF" )
    {
        std::cout << magic_s << " != OFF :   We handle ONLY *.off files." << std::endl;
        myfile.close();
        return false;
    }

    int n_vertices , n_faces , dummy_int;
    myfile >> n_vertices >> n_faces >> dummy_int;

    position.resize(n_vertices);

    for( int v = 0 ; v < n_vertices ; ++v )
    {
        glm::vec3 vertex;
        myfile >> vertex.x >> vertex.y >> vertex.z;
        if( std::isnan(vertex.x) )
            vertex.x = 0.0;
        if( std::isnan(vertex.y) )
            vertex.y = 0.0;
        if( std::isnan(vertex.z) )
            vertex.z = 0.0;
        position[v] = vertex;
//         std::cout<< vertex.x  <<" " << vertex.y << " "<< vertex.z<< std::endl;
    }


    for( int f = 0 ; f < n_faces ; ++f )
    {
        int n_vertices_on_face;
        myfile >> n_vertices_on_face;
        if( n_vertices_on_face == 3 )
        {
            unsigned short _v1 , _v2 , _v3;
            myfile >> _v1 >> _v2 >> _v3;
            indices.push_back( _v1 );
            indices.push_back( _v2 );
            indices.push_back( _v3 );

        }
        else
        {
            std::cout << "OFFIO::open error : Face number " << f << " has " << n_vertices_on_face << " vertices" << std::endl;
            myfile.close();
            return false;
        }
    }

    myfile.close();
    return true;
}

// bool Mesh::loadAssImp(const char * path){
// 
//     Assimp::Importer importer;
// 
//     const aiScene* scene = importer.ReadFile(path, 0/*aiProcess_JoinIdenticalVertices | aiProcess_SortByPType*/);
//     if( !scene) {
//         fprintf( stderr, importer.GetErrorString());
//         getchar();
//         return false;
//     }
//     const aiMesh* mesh = scene->mMeshes[0]; // In this simple example code we always use the 1rst mesh (in OBJ files there is often only one anyway)
// 
//     Fill position positions
//     position.reserve(mesh->mNumVertices);
//     for(unsigned int i=0; i<mesh->mNumVertices; i++){
//         aiVector3D pos = mesh->mVertices[i];
//         position.push_back(glm::vec3(pos.x, pos.y, pos.z));
//     }
// 
//     Fill position texture coordinates
//     tex_coords.reserve(mesh->mNumVertices);
//     for(unsigned int i=0; i<mesh->mNumVertices; i++){
//         aiVector3D UVW = mesh->mTextureCoords[0][i]; // Assume only 1 set of UV coords; AssImp supports 8 UV sets.
//         tex_coords.push_back(glm::vec2(UVW.x, UVW.y));
//     }
// 
//     Fill position normals
//     normals.reserve(mesh->mNumVertices);
//     for(unsigned int i=0; i<mesh->mNumVertices; i++){
//         aiVector3D n = mesh->mNormals[i];
//         normals.push_back(glm::vec3(n.x, n.y, n.z));
//     }
// 
// 
//     Fill face indices
//     indices.reserve(3*mesh->mNumFaces);
//     for (unsigned int i=0; i<mesh->mNumFaces; i++){
//         Assume the model has only triangles.
//         indices.push_back(mesh->mFaces[i].mIndices[0]);
//         indices.push_back(mesh->mFaces[i].mIndices[1]);
//         indices.push_back(mesh->mFaces[i].mIndices[2]);
//     }
// 
//     The "scene" pointer will be deleted automatically by "importer"
//     return true;
// }


void Mesh::settexture( const std::string & path , GLuint textureIndex, const std::string & name_in_shader) 
{
renderer.stocktexture(path, textureIndex, name_in_shader); 
}
void Mesh::initobject() 
{
renderer.genbuffer(position , normals , tex_coords  ,indices);
}
void Mesh::drawobject() 
{
    
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
glUniform1f(glGetUniformLocation(renderer.programID,"shininess"), (this->getshininess()));
glUniform3fv(glGetUniformLocation(renderer.programID,"mesh_color"), 1 , &(this->getcolor())[0]);
glUniformMatrix4fv(glGetUniformLocation(renderer.programID,"modelmat"), 1 , GL_FALSE, &(this->getmodelmat())[0][0]);
renderer.loadtextures(); 
renderer.draw(); 
}

void Mesh::deleteobject() 
{
renderer.deletebuffers(); 
delete this;
}

