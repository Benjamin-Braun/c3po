#include "main.h"

struct ConfigStruct {
	int screenWidth;
	int screenHeight;
	bool fullscreen;
	string model;
	int targetFPS;
	int monitorWidth;
	int monitorHeight;
	int copyrightX;
	int copyrightY;
};

struct ContextStruct {
	bool gridEnable = true;
	int grid1 = 20;
	float grid2 = 10.0f;
	int gridType = 0;
	float gridColor[4] = {1, 1, 1, 1};
	float backgroundColor[4] = {0, 0, 0, 0};
	bool modelEnable = true;
	int modelDrawMode = 0;
	float modelColor[4] = {1, 1, 1, 1};
	Vector3 modelScale = {1, 1, 1};
	Vector3 modelPosition = {0, 0, 0};
	Vector3 modelRotation = {0, 0, 0};
	float modelRotationAngle = 0;
	
	bool cameraEnable = true;
	int camerType = 0;
};

ConfigStruct config;
ContextStruct context;

bool helpWin = false;
bool graphicsWin = false;
bool modelWin = false;
bool cursorVisible = true;

ConfigStruct ParseArgs(int argc, char* argv[]){
	if(argc < 2){
		cout << "Invalid argument count!" << endl << "c3po <model> <width> <height> <fullscreen>" << endl;
		//exit(1);
	}

	ConfigStruct newConfig;
	newConfig.screenWidth = 1280;
	newConfig.screenHeight = 720;
	newConfig.fullscreen = false;
	for(int i=1; i<argc; i++){
		string arg = argv[i];
		if(i == 2) newConfig.screenWidth = atoi(arg.c_str());
		if(i == 3) newConfig.screenHeight = atoi(arg.c_str());
		if(i == 4) newConfig.fullscreen = stoi(arg.c_str());;
		if(i == 1) newConfig.model = arg;
	}
	return newConfig;
}

Color float4tocolor(float flts[4]){
	//cout << flts[0] << " : " << flts[1] << " : " << flts[2] << " : " << flts[3] << endl;
	return (Color){(unsigned char)(255*flts[0]), (unsigned char)(255*flts[1]), (unsigned char)(255*flts[2]), (unsigned char)(255*flts[3])};
}

Color reversefloat4tocolor(float flts[4]){
	//cout << flts[0] << " : " << flts[1] << " : " << flts[2] << " : " << flts[3] << endl;
	return (Color){(unsigned char)(255-(255*flts[0])), (unsigned char)(255-(255*flts[1])), (unsigned char)(255-(255*flts[2])), (unsigned char)(255-(255*flts[3]))};
}

void fullscreen(){
	int display = GetCurrentMonitor();
    if (IsWindowFullscreen()){
    	SetWindowSize(config.screenWidth, config.screenHeight);
		config.copyrightX = config.screenWidth-5*34;
		config.copyrightY = config.screenHeight-10;
    }else{
    	SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
		config.copyrightX = config.monitorWidth-5*34;
		config.copyrightY = config.monitorHeight-10;
    }
 	ToggleFullscreen();
}

int main(int argc, char* argv[]){
	config = ParseArgs(argc, argv);
	config.targetFPS = 60;
	config.copyrightX = config.screenWidth-5*34;
	config.copyrightY = config.screenHeight-10;

	SetTraceLogLevel(LOG_ERROR); 
	SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
	InitWindow(config.screenWidth, config.screenHeight, "C-3PO");
	SetTargetFPS(config.targetFPS);
	if(config.fullscreen) ToggleFullscreen();
	rlImGuiSetup(true);

	Camera camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 5.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
	Model model = LoadModel(config.model.c_str());

	int display = GetCurrentMonitor();
	config.monitorWidth = GetMonitorWidth(display);
	config.monitorHeight = GetMonitorHeight(display);

	while (!WindowShouldClose()){
		if(IsKeyPressed(KEY_F11)) fullscreen();
		if(IsKeyPressed(KEY_F1)) helpWin = !helpWin;
		if(IsKeyPressed(KEY_F2)){
			cursorVisible = !cursorVisible;
            if (cursorVisible)
                EnableCursor();
            else
                DisableCursor();
		}
		if(IsKeyPressed(KEY_F10)) graphicsWin = !graphicsWin;
		if(IsKeyPressed(KEY_TAB)) modelWin = !modelWin;
		
		if(context.camerType == 0) UpdateCamera(&camera, CAMERA_ORBITAL);
		if(context.camerType == 2) UpdateCamera(&camera, CAMERA_FIRST_PERSON);
		if(context.camerType == 3) UpdateCamera(&camera, CAMERA_FREE);
		if(context.camerType == 1){}
		
		BeginDrawing();
		ClearBackground(float4tocolor(context.backgroundColor));
		DrawText("Copyright © 2025 Benjamin Braun", config.copyrightX, config.copyrightY, 5, reversefloat4tocolor(context.backgroundColor));
		if(context.cameraEnable){
			BeginMode3D(camera);
        	    if(context.modelEnable){
					if(context.modelDrawMode == 0) DrawModelEx(model, context.modelPosition, context.modelRotation, 0, context.modelScale, float4tocolor(context.modelColor));
					if(context.modelDrawMode == 1) DrawModelWiresEx(model, context.modelPosition, context.modelRotation, 0, context.modelScale, float4tocolor(context.modelColor));
					if(context.modelDrawMode == 2) DrawModelPointsEx(model, context.modelPosition, context.modelRotation, 0, context.modelScale, float4tocolor(context.modelColor));
				}
        	    if(context.gridEnable){
					if(context.gridType == 0) DrawGrid(context.grid1, context.grid2);
					if(context.gridType == 1) DrawPlane((Vector3){0, 0, 0}, (Vector2){context.grid1*context.grid2, context.grid1*context.grid2}, float4tocolor(context.gridColor));
				}
        	EndMode3D();
		}

		rlImGuiBegin();
			if(graphicsWin){
				ImGui::Begin("Display Settings");
					ImGui::SeparatorText("Resolution");
					ImGui::InputInt("Width", &config.screenWidth, 10);
					ImGui::InputInt("Height", &config.screenHeight, 10);
					ImGui::SeparatorText("Display");
					ImGui::Checkbox("Fullscreen", &config.fullscreen);
					ImGui::InputInt("Target FPS", &config.targetFPS);
					if(ImGui::Button("Apply")){
						SetWindowSize(config.screenWidth, config.screenHeight);
						if(config.fullscreen && !IsWindowFullscreen()) ToggleFullscreen();
						if(!config.fullscreen && IsWindowFullscreen()) ToggleFullscreen();
						SetTargetFPS(config.targetFPS);
						config.copyrightX = config.monitorWidth-5*34;
						config.copyrightY = config.monitorHeight-10;
					}
				ImGui::End();
			}
			if(modelWin){
				ImGui::Begin("Tweaks");
					if(ImGui::CollapsingHeader("Display")){
						if(ImGui::TreeNode("Grid")){
							ImGui::Checkbox("Enable Grid", &context.gridEnable);
							const char* items[] = { "Grid", "Plane" };
            				ImGui::Combo("Grid Type", &context.gridType, items, IM_ARRAYSIZE(items));
							ImGui::SliderInt("Grid Size", &context.grid1, 1, 400);
							ImGui::InputFloat("Grid Tile Size", &context.grid2, 0.1f);
							ImGui::ColorEdit4("Grid Color", context.modelColor);
							ImGui::TreePop();
						}
						if(ImGui::TreeNode("Model")){
							ImGui::Checkbox("Enable Model", &context.modelEnable);
							const char* items[] = { "Normal", "Wireframe", "Points" };
            				ImGui::Combo("Draw Mode", &context.modelDrawMode, items, IM_ARRAYSIZE(items));
							ImGui::ColorEdit4("Model Color", context.modelColor);
							//ImGui::InputFloat("Scale", &context.modelScale, 0.1f);
							if(ImGui::TreeNode("Position")){
								ImGui::InputFloat("Position X", &context.modelPosition.x, 0.1f);
								ImGui::InputFloat("Position Y", &context.modelPosition.y, 0.1f);
								ImGui::InputFloat("Position Z", &context.modelPosition.z, 0.1f);
								ImGui::TreePop();
							}
							if(ImGui::TreeNode("Scale")){
								ImGui::InputFloat("Scale X", &context.modelScale.x, 0.1f);
								ImGui::InputFloat("Scale Y", &context.modelScale.y, 0.1f);
								ImGui::InputFloat("Scale Z", &context.modelScale.z, 0.1f);
								ImGui::TreePop();
							}
							if(ImGui::TreeNode("Rotation")){
								ImGui::InputFloat("Rotation X", &context.modelRotation.x, 0.1f);
								ImGui::InputFloat("Rotation Y", &context.modelRotation.y, 0.1f);
								ImGui::InputFloat("Rotation Z", &context.modelRotation.z, 0.1f);
								ImGui::InputFloat("Rotation Angle", &context.modelRotationAngle, 0.1f);
								ImGui::TreePop();
							}
							ImGui::TreePop();
						}
						if(ImGui::TreeNode("Background")){
							ImGui::ColorEdit4("Background Color", context.backgroundColor);
							ImGui::TreePop();
						}
					}
					if(ImGui::CollapsingHeader("Camera")){
						ImGui::Checkbox("Camera Enable", &context.cameraEnable);
						const char* items[] = { "Orbital", "Static", "First Person", "Free" };
            			ImGui::Combo("Draw Mode", &context.camerType, items, IM_ARRAYSIZE(items));
						if(ImGui::Button("Camera Reset")){
							camera.position = (Vector3){ 5.0f, 5.0f, 5.0f };
    						camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    						camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    						camera.fovy = 45.0f;
    						camera.projection = CAMERA_PERSPECTIVE;
						}
						ImGui::InputFloat("FOV", &camera.fovy, 5);
						if(ImGui::TreeNode("Position")){
							ImGui::InputFloat("Position X", &camera.position.x, 0.1f);
							ImGui::InputFloat("Position Y", &camera.position.y, 0.1f);
							ImGui::InputFloat("Position Z", &camera.position.z, 0.1f);
							ImGui::TreePop();
						}
						if(ImGui::TreeNode("Target")){
							ImGui::InputFloat("Target X", &camera.target.x, 0.1f);
							ImGui::InputFloat("Target Y", &camera.target.y, 0.1f);
							ImGui::InputFloat("Target Z", &camera.target.z, 0.1f);
							ImGui::TreePop();
						}
						if(ImGui::TreeNode("Up")){
							ImGui::InputFloat("Up X", &camera.up.x, 0.1f);
							ImGui::InputFloat("Up Y", &camera.up.y, 0.1f);
							ImGui::InputFloat("Up Z", &camera.up.z, 0.1f);
							ImGui::TreePop();
						}
					}
				ImGui::End();
			}
			if(helpWin){
				ImGui::Begin("Help");
					if(ImGui::CollapsingHeader("General")){

					}
					if(ImGui::CollapsingHeader("Display")){

					}
					if(ImGui::CollapsingHeader("Tweaks")){

					}
					if(ImGui::CollapsingHeader("Support")){

					}
					if(ImGui::CollapsingHeader("About")){
						ImGui::Text("C-3PO v0.3.1");
						//ImGui::Text("------------");
						ImGui::Text("Copyright © 2025 Benjamin Braun");
						ImGui::Text("Licensed under MIT License");
					}
				ImGui::End();
			}
		rlImGuiEnd();

		EndDrawing();
	}
	rlImGuiShutdown();
	CloseWindow();

	return 0;
}