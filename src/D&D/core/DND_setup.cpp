#include "DND.h"

const char* title = "種族";
char buf[125];
const char* genre[15] = {
    "人類", "變種人類", "半獸人", "半精靈", "強半身人", "輕半身人",
    "岩地侏", "森地侏", "提夫林", "丘陵矮人", "高山矮人", "卓爾", 
    "森精靈", "高等精靈", "龍裔"
}; 
static const char* current_item = NULL;

std::string DND::races = "";
std::string DND::classes = "";
int DND::setup_page = 0;

// cmd set chcp 65001 to utf-8
void DND::setup(){
    sprintf(buf, "初始設定 - %s###setup_title", title);
    ImGui::Begin(buf);
    switch (setup_page)
    {
    case 0:
        title = "種族";
        race_setup();
        break;
    case 1:
        title = "職業";
        break;
    default:
        break;
    }
    ImGui::End();
}

void DND::race_setup(){
    File in = File("assets\\json\\race.json");
    nlohmann::json raw_race_json;
    in.getStream() >> raw_race_json;
    float fontSize = ImGui::GetFontSize();

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

            std::string attr[6] = {"力量", "敏捷", "體質", "智力", "睿知", "魅力"};
            if(character.contains("屬性值")){
                tmp_output += "屬性值: ";
                for(int i = 0; i < 5; i++){
                    int att = character["屬性值"][i];
                    if(att != 0)
                        tmp_output += attr[i] + "+" + std::to_string(att) + " ";
                }
                ImGui::BulletText(tmp_output.c_str());
                tmp_output.clear();
            }

            if(character.contains("體型")){
                tmp_output += "體型: " + character["體型"].dump();
                ImGui::BulletText(tmp_output.c_str());
                tmp_output.clear();
            }
            if(character.contains("速度")){
                tmp_output += "速度: " + character["速度"].dump() + "呎";
                ImGui::BulletText(tmp_output.c_str());
                tmp_output.clear();
            }

            ImGui::SeparatorText("介紹");
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
    
    ImGui::Separator();
    ImGui::NewLine();
    ImGui::SameLine(ImGui::GetContentRegionMax().x - 5.0f*fontSize);
    if(ImGui::Button("重置")){
        current_item = NULL;
        DND::races = "";
    }
    ImGui::SameLine();
    if(ImGui::Button("下一步") && current_item){
        DND::races = current_item;
        setup_page++;
    }
}

void DND::classes_setup(){

}