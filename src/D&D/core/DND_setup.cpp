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
    nlohmann::json raw_race_json;
    in.getStream() >> raw_race_json;

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

    nlohmann::json character;

    for(auto it: raw_race_json.items()){
        if(current_item && current_item == it.key()){
            std::string tmp_output;
            ImGui::SeparatorText(current_item);
            character = it.value()["character"];

            for(auto it2: character.items()){
                if(it2.key() == "description")
                    continue;
                tmp_output += it2.key() + ". " + it2.value().dump();
                ImGui::BulletText(tmp_output.c_str());
                tmp_output.clear();
            }

            ImGui::SeparatorText("");
            nlohmann::json description = character["description"];

            for(auto it2: description.items()){
                int size = it2.value().dump().length();
                tmp_output += it2.key() + ". ";
                ImGui::BulletText(tmp_output.c_str());
                ImGui::Indent();
                ImGui::TextWrapped(it2.value().dump().substr(1, size-2).c_str());
                ImGui::Unindent();
                tmp_output.clear();
            }
        }
    }

    ImGui::End();
}