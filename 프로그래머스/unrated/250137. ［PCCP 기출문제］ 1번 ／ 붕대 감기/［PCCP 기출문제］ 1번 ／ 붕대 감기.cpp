#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    // bandage: 시전 시간, 초당 회복량, 추가 회복량
    const int ADDITIONAL_HEAL_TIME = bandage[0];
    const int HEAL = bandage[1];
    const int ADDITIONAL_HEAL = bandage[2];
    // 최대 체력
    const int MAX_HEALTH = health;
    // attacks: 공격 시간, 피해량
    const int LAST_TIME = attacks[attacks.size() - 1][0];
    
    int attack_pointer = 0;
    bool attack_flag = false;
    int bondage_timer = 0;
    for(int i = 0; i <= LAST_TIME; i++){
        // 공격을 당했는지 먼저 체크
        if(attacks[attack_pointer][0] == i){ // 공격 타이밍일 때,
            attack_flag = true;
            bondage_timer = 0;
            health -= attacks[attack_pointer][1];
            if(health <= 0){ // 죽었을 경우
                return -1;
            }
            if(i == LAST_TIME){
                return health;
            }
            
            attack_pointer++;
        }
        
        // 공격을 맞지 않았을 경우 힐
        if(attack_flag == false){
            if(bondage_timer == ADDITIONAL_HEAL_TIME){
                health = (health + HEAL + ADDITIONAL_HEAL) >= MAX_HEALTH ? MAX_HEALTH : health + HEAL + ADDITIONAL_HEAL;
                bondage_timer = 0;
            }else{
                health = (health + HEAL) >= MAX_HEALTH ? MAX_HEALTH : health + HEAL;
            }
        }
        
        // 턴이 끝나기 전에 세팅 해놓아야 할 것들
        bondage_timer++;
        attack_flag = false;
}
    
    return health;
}