enum BodyPart
{
    BODY_PART_HEAD,
    BODY_PART_CHEST,
    BODY_PART_LEGS
};

enum GunType
{
    GUN_PISTOL,
    GUN_SHOTGUN,
    GUN_RIFLE
};

struct Player
{
    Float health;
    Float armor;
    // Other player properties
};

stock ApplyDamage(Float:baseDamage, BodyPart:bodyPart, GunType:gunType, Player &player)
{
    Float:damageMultiplier;

    switch (bodyPart)
    {
        case BODY_PART_HEAD:
            damageMultiplier = 2.0;
            break;

        case BODY_PART_CHEST:
            damageMultiplier = 1.0;
            break;

        case BODY_PART_LEGS:
            damageMultiplier = 0.5;
            break;

        default:
            damageMultiplier = 1.0;
            break;
    }

    // Adjust damage based on the type of gun
    switch (gunType)
    {
        case GUN_PISTOL:
            baseDamage *= 1.2;
            break;

        case GUN_SHOTGUN:
            baseDamage *= 0.8;
            break;

        case GUN_RIFLE:
            baseDamage *= 1.5;
            break;

        default:
            break;
    }

    Float:finalDamage = baseDamage * damageMultiplier;

    // Apply armor reduction if player has armor
    if (player.armor > 0.0)
    {
        Float:armorReduction = finalDamage * 0.5;  // Example armor reduction factor
        player.armor -= armorReduction;

        // Ensure armor value doesn't go below zero
        if (player.armor < 0.0)
            player.armor = 0.0;

        finalDamage -= armorReduction;
    }

    // Apply the final damage to the player
    if (bodyPart == BODY_PART_HEAD && finalDamage >= player.health)
    {
        // Headshot kill - player dies instantly
        player.health = 0.0;
    }
    else
    {
        // Normal damage application
        player.health -= finalDamage;
    }

    // Check if the player is dead
    if (player.health <= 0.0)
    {
        // Player is dead, perform necessary actions (e.g., respawn, end the game)
        // Your implementation here
    }
    else
    {
        // Player is still alive, perform necessary actions (e.g., show damage effects, update UI)
        // Your implementation here
    }

    return finalDamage;
}
