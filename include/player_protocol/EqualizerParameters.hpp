#pragma once
#include <array>

namespace player_protocol {
    class EqualizerParameters {
    public:
        EqualizerParameters();

        [[nodiscard]] float getGainDb() const;
        void setGainDb(float gainDb);

        [[nodiscard]] std::array<float, 10>& getFrequencyGainDb();
        void setFrequencyGainDb(const std::array<float, 10> &frequencyGainDb);

        [[nodiscard]] float getFrequencyAt(std::size_t idx) const;
        [[nodiscard]] float getGainDbAt(std::size_t idx) const;
        void setGainDbAt(std::size_t idx, float gainDb);
    private:
        float gainDb;
        std::array<float, 10> frequencyGainDb;
    };
}
