#include <iostream>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

int main(int argc, char **argv) {

  // Create an instance of the Importer class
  Assimp::Importer importer;
  // And have it read the given file with some example postprocessing
  // Usually - if speed is not the most important aspect for you - you'll 
  // propably to request more postprocessing than we do in this example.
  const aiScene* scene = importer.ReadFile( "/home/skotti/projects/game_starting_from_shadows/game/models/cube_textured.obj", 
        /*aiProcess_CalcTangentSpace       | 
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType*/
																					
		aiProcess_CalcTangentSpace       | 
		aiProcess_Triangulate            |
		aiProcess_JoinIdenticalVertices  |
		aiProcess_FlipUVs |
		aiProcess_FlipWindingOrder |
		
		aiProcess_GenNormals
				
	);
  
  // If the import failed, report it
  if( !scene)
  {
    return false;
  }
  aiString path;
	int text_index =0 ;
	aiString name;
	aiString color;
	std::cout<<"Num materials:"<<scene->mNumMaterials<<std::endl;
	int ar[3];
	
	for (int i = 0; i < scene->mNumMeshes; i++) {
		std::cout<<"Material index of mesh "<<i<<" is "<<scene->mMeshes[i]->mMaterialIndex<<std::endl;
	}
	
  for (int i = 0; i < scene->mNumMaterials; i++) {
		aiTextureType text_types[] = {
			aiTextureType_NONE,
			aiTextureType_DIFFUSE,
			aiTextureType_SPECULAR,
			aiTextureType_AMBIENT,
			aiTextureType_EMISSIVE,
			aiTextureType_HEIGHT,
			aiTextureType_NORMALS,
			aiTextureType_SHININESS,
			aiTextureType_OPACITY,
			aiTextureType_DISPLACEMENT,
			aiTextureType_LIGHTMAP,
			aiTextureType_REFLECTION,
			aiTextureType_UNKNOWN};
		int num;
		scene->mMaterials[i]->Get(AI_MATKEY_NAME,name);
		std::cout<<"Material name : "<<name.data<<std::endl;
		aiColor3D color_diffuse (0.f,0.f,0.f);
		scene->mMaterials[i]->Get(AI_MATKEY_COLOR_DIFFUSE,color_diffuse);
		std::cout<<"Diffuse color : "<<color_diffuse.r<<" "<<color_diffuse.g<<" "<<color_diffuse.b<<std::endl;
		
		float shininess;
		scene->mMaterials[i]->Get(AI_MATKEY_SHININESS, shininess);
		std::cout<<"Shininess : "<<shininess<<std::endl;
		
		float shininess_strength;
		scene->mMaterials[i]->Get(AI_MATKEY_SHININESS_STRENGTH, shininess_strength);
		std::cout<<"Shininess strength: "<<shininess_strength<<std::endl;
		
		for (int j= 0; j < 13;j++) {
			num = scene->mMaterials[i]->GetTextureCount(text_types[j]);

			std::cout<<num<<std::endl;
			for(int k = 0; k < num; k++) {
				aiReturn text = scene->mMaterials[i]->GetTexture(text_types[j],k,&path,NULL,NULL,NULL,NULL,NULL);
				std::cout<<std::string(path.C_Str())<<std::endl;
			}
		}
		std::cout<<"--------------"<<std::endl;
		//text_index++;
	}

}
