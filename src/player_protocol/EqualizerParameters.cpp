#include "EqualizerParameters.hpp"

namespace player_protocol {
    EqualizerParameters::EqualizerParameters()
        : gainDb(0.0F)
        , frequencyGainDb{}
    {}

    float EqualizerParameters::getGainDb() const {
        return gainDb;
    }

    void EqualizerParameters::setGainDb(float gainDb) {
        this->gainDb = gainDb;
    }

    std::array<float, 10> &EqualizerParameters::getFrequencyGainDb() {
        return frequencyGainDb;
    }

    void EqualizerParameters::setFrequencyGainDb(const std::array<float, 10> &frequencyGainDb) {
        this->frequencyGainDb = frequencyGainDb;
    }

    float EqualizerParameters::getGainDbAt(std::size_t idx) const {
        return frequencyGainDb.at(idx);
    }

    void EqualizerParameters::setGainDbAt(std::size_t idx, float gainDb) {
        frequencyGainDb.at(idx) = gainDb;
    }
}