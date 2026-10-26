#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void displaySpellBanner( string spellName, string tier = "Novice", int chargeLevel= 1);

double castSpell( string spellName = "Magic ball", int basePower = 2, double multiplier = 1.0);

double calculateShield(double baseShield = 15, double absorptionRate = 0.2);

int registerCombo(bool hitSuccessful);

void consumeMana(int manaCost = 5);

bool processBossRage(double damageDealt);

int gainWizardXP(int xpGained = 25);



int main() {
    cout << "=== WIZARD ACADEMY BATTLE SIMULATOR ===\n\n";

    char continueBattle = 'y';
    int turn = 1;

    while (continueBattle == 'y' || continueBattle == 'Y') {
        cout << "\n----------------------------------------\n";
        cout << " TURN " << turn << "\n";
        cout << "----------------------------------------\n";

        int choice = 0;
        cout << "Select Action:\n";
        cout << "1) Quick Magic Missile (Default attack)\n";
        cout << "2) Heavy Lightning Storm (Custom attack)\n";
        cout << "3) Cast Defensive Barrier\n";
        cout << "4) Miss Attack Intentionally\n";
        cout << "Choice: ";
        cin >> choice;

        double damageDealt = 0.0;
        bool successfulHit = false;

        if (choice == 1) {
            displaySpellBanner("Magic Missile");
            damageDealt = castSpell(); // Uses default arguments
            consumeMana();             // Uses default mana cost (5)
            successfulHit = true;
        } 
        else if (choice == 2) {
            displaySpellBanner("Fireball", "Adept", 2);
            damageDealt = castSpell("Fireball", 30, 1.4);
            consumeMana(15);           // Custom mana cost
            successfulHit = true;
        } 
        else if (choice == 3) {
            displaySpellBanner("Arcane Shield", "Novice", 1);
            double shieldVal = calculateShield(20.0, 0.25);
            cout << "Shield generated! Absorbs " << shieldVal << " incoming damage.\n";
            consumeMana(8);
            successfulHit = true;
        } 
        else {
            cout << "Your attack missed completely!\n";
            successfulHit = false;
        }

        // --- UPDATE PERSISTENT GAME STATE VIA STATIC FUNCTIONS ---
        int currentCombo = registerCombo(successfulHit);
        if (successfulHit) {
            cout << "Current Combo Streak: " << currentCombo << "x\n";
            gainWizardXP(30); // Award XP for hitting
        }

        // Check if boss enters enrage mode
        bool isBossEnraged = processBossRage(damageDealt);
        if (isBossEnraged) {
            cout << "!!! WARNING: BOSS HAS ENTERED ENRAGE MODE !!!\n";
        }

        turn++;
        cout << "\nEnd turn? Continue fighting? (y/n): ";
        cin >> continueBattle;
    }

    cout << "\n=== BATTLE SIMULATION ENDED ===\n";
    return 0;
}

// Display yourself casting a spell
void displaySpellBanner( string spellName, string tier, int chargeLevel){
    cout << "V=== CASTING SPELL ===V\n";
    cout << "Spell: " << spellName << "\n";
    cout << "Tier: " << tier << "\n";
    cout << "Charge Level: " << chargeLevel << "\n\n";
}
// spell casting
double castSpell( string spellName, int basePower, double multiplier){
    cout << "Casting " << spellName << "!\n";
    cout << "Base Power: " << basePower << "\n";
    cout << "Multiplier: " << multiplier << "\n";
    return basePower * multiplier;
}

//defenseive actions function 
double calculateShield(double baseShield, double absorptionRate){
    cout << "Calculating Ward...\n";
    cout << "Base Shield: " << baseShield << "\n";
    cout << "Absorption Rate: " << absorptionRate << "\n";
    return baseShield * (1 + absorptionRate);
}

//combo function

int registerCombo(bool hitSuccessful){
    static int comboCount = 0;
    if (hitSuccessful) {
        comboCount++;
    }   
    else {
        comboCount = 0;
        cout << "Combo broken! You missed your spell!!!!!\n";
    }
    return comboCount;
}
//consuming mana
void consumeMana(int manaCost){
    static int totalManaConsumed = 0;
    totalManaConsumed += manaCost;
    cout << "Total mana consumed this battle: " << totalManaConsumed << "\n";
}
//Ability to do more damage
bool processBossRage(double damageDealt){
    static double totalDamageDealt = 0.0;
    totalDamageDealt += damageDealt;

    if (totalDamageDealt >= 100.0) {
        return true; 
    }
    return false;
}
//XP and levels function
int gainWizardXP(int xpGained){
    static int totalXP = 0;
    static int wizardLevel = 1;
    totalXP += xpGained;
    cout << "Total Wizard XP: " << totalXP << "\n";
    if (totalXP >= wizardLevel * 100) {
        wizardLevel++;
        cout << "LEVEL UP!\n" << endl;
    }
    return wizardLevel;
}





