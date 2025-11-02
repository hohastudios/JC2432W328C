# Bluetooth Macrokeys ESP32 JC2432W28C Guition implementation

## Features 
 - EEZ studio -> LVGl mative cpp implementation

 - BleKeyboard library

 - Loads json profiles from Sd card by reading macrokeys/config folder

 - Two Tab 3x2 Custom buttons, button box

Todo: deserialise json and map from config

## Flow diagram (on going)
```mermaid
sequenceDiagram
    participant User
    participant ProfileSelectorView
    participant RollerElement
    participant OkButton
    participant configReader
    participant MainPage
    participant Vars
    participant Actions

    User->>ProfileSelectorView: Load View
    ProfileSelectorView->>configReader: OnLoad()
    configReader->>configReader: ReadSd()
    configReader->>configReader: Read folder config for JSON configs
    configReader-->>ProfileSelectorView: Return JSON configs
    ProfileSelectorView->>RollerElement: Populate dynamically

    User->>OkButton: Press OK
    OkButton->>ProfileSelectorView: OnOkPressed()
    ProfileSelectorView->>configReader: ChangeScreen(MainPage)
    configReader->>configReader: Load JSON file path
    configReader->>configReader: Deserialize JSON object
    configReader->>Vars: Load label and button mappings
    configReader-->>MainPage: Switch to MainPage

    MainPage->>MainPage: OnMainPageLoad()
    MainPage->>Vars: Get label mappings
    MainPage->>MainPage: Populate label elements
    MainPage->>Actions: Map button press
```