#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void displaySpellBanner( string spellName, string tier = "Novice", int chargeLevel= 1);

double castSpell( string spellName = "Magic ball", int basePower = 2, double multiplier = 1.0);

double calculateShield(double baseShield = 15, double absorptionRate = 0.2);











int main() {
    cout << "=== ARENA WARM-UP: TESTING DEFAULT ARGUMENTS ===\n\n";

    // Call 1: Uses defaults for tier ("Novice") and chargeLevel (1)
    displaySpellBanner("Magic Missile");
    double dmg1 = castSpell(); // Uses all defaults: "Magic Missile", 10, 1.0
    double ward1 = calculateShield(); // Uses defaults: 15.0, 0.20
    cout << "Ward Absorbs: " << ward1 << " HP\n\n";

    // Call 2: Fully customized spell call
    displaySpellBanner("Inferno Fireball", "Master", 3);
    double dmg2 = castSpell("Inferno Fireball", 35, 1.5);
    double ward2 = calculateShield(30.0, 0.50);
    cout << "Ward Absorbs: " << ward2 << " HP\n\n";

    return 0;
}



void displaySpellBanner( string spellName, string tier, int chargeLevel){
    cout << "V=== CASTING SPELL ===V\n";
    cout << "Spell: " << spellName << "\n";
    cout << "Tier: " << tier << "\n";
    cout << "Charge Level: " << chargeLevel << "\n\n";
}
/*This function will take default arguments for all fields–spellName (a weak spell of your choice), basePower (your choice) and multiplier (default will be 1).
The purpose of the function is to print the attack summary and calculate the total damage (basePower * multiplier) and return it as a double.
*/
double castSpell( string spellName, int basePower, double multiplier){
    cout << "Casting " << spellName << "!\n";
    cout << "Base Power: " << basePower << "\n";
    cout << "Multiplier: " << multiplier << "\n";
    return basePower * multiplier;
}
/*This function will take default arguments for baseShield (15) and absorptionRate(.2).
The purpose of this function is to calculate the absorbed damage (baseShield * (1+ absorptionRate).  
It should return total ward value as a double.
*/
double calculateShield(double baseShield, double absorptionRate){
    cout << "Calculating Ward...\n";
    cout << "Base Shield: " << baseShield << "\n";
    cout << "Absorption Rate: " << absorptionRate << "\n";
    return baseShield * (1 + absorptionRate);
}


