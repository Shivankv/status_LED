#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t state;       // 1 for ON, 0 for OFF
    uint8_t brightness;  // Brightness (0-255)
    uint32_t color;      // RGB color
} LEDSettings;

typedef struct {
    LEDSettings singleLED;
    uint8_t groupState;    // 1 for ALL ON, 0 for ALL OFF
    uint8_t groupBrightness; // Group brightness
} LEDGroup;

void initLEDGroup(LEDGroup *group) {
    group->singleLED = (LEDSettings){0, 0, 0x000000}; // LED OFF, brightness 0, black
    group->groupState = 0;
    group->groupBrightness = 0;
}

void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, 
                            uint8_t state, uint8_t brightness, uint32_t color) {
    group->singleLED = (LEDSettings){state, brightness, color};
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;
}

void displayLEDGroupStatus(const LEDGroup *group) {
    printf("LED State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("Brightness: %u\n", group->singleLED.brightness);
    printf("Color: 0x%06X\n", group->singleLED.color);
    printf("Group State: %s\n", group->groupState ? "ALL ON" : "ALL OFF");
    printf("Group Brightness: %u\n", group->groupBrightness);
}

int main() {
    LEDGroup myLEDGroup;
    initLEDGroup(&myLEDGroup);
    
    printf("Initial LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);

    updateLEDGroupSettings(&myLEDGroup, 1, 150, 1, 200, 0xFF5733);
    
    printf("\nUpdated LED Group Status:\n");
    displayLEDGroupStatus(&myLEDGroup);
    
    return 0;
}
