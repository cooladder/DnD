#include "DND.h"

const char* genre[15] = {
    "人類", "變種人類", "半獸人", "半精靈", "強半身人", "輕半身人",
    "岩地侏", "森地侏", "提夫林", "丘陵矮人", "高山矮人", "卓爾", 
    "森精靈", "高等精靈", "龍裔"
}; 
static const char* current_item = NULL;


// cmd set chcp 65001 to utf-8
void DND::setup(){
    File in = File("assets\\json\\race.json");
    nlohmann::json j;
    in.getStream() >> j;
    for(auto it: j.items()){
        std::cout << it.key() << std::endl;
    }

    ImGui::Begin(u8"初始設定");
    if (ImGui::BeginCombo("##combo", current_item)){ 
        for (int n = 0; n < 15; n++){
            bool is_selected = (current_item == genre[n]); 
            if (ImGui::Selectable(genre[n], is_selected))
                current_item = genre[n];
            if (is_selected)
                ImGui::SetItemDefaultFocus(); 
        }
        ImGui::EndCombo();
    }
    ImGui::End();
}