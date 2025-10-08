#pragma once

#include <MemoryPatterns/PatternTypes/UiItem3dPanelPatternTypes.h>
#include <MemorySearch/CodePattern.h>

struct UiItem3dPanelPatterns {
    [[nodiscard]] static consteval auto addClientPatterns(auto clientPatterns) noexcept
    {
        return clientPatterns
            .template addPattern<SetItemItemIdFunction, CodePattern{"4C 89 44 24 ? 48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 54 41 56 41"}>()
            .template addPattern<OffsetToItem3dPanelUnknownField, CodePattern{"39 ? ? ? ? ? 75 ? 45 84 ? 0F"}.add(2).read()>()
            .template addPattern<OffsetToStartWeaponLookAt, CodePattern{"81 ? ? ? ? 01 00 C3"}.add(1).read()>();
    }
};
