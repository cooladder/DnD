#include"DND.h"

void DND::build(){
    ImGui::Begin("角色建構");
    ImGui::BulletText("種族: "); ImGui::SameLine();
    ImGui::Text(DND::races.c_str()); ImGui::Separator();
    ImGui::End();
}