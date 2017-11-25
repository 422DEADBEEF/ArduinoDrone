#include "Arduino.h"
#include "Frequencies.h"

namespace {
    const int kMaxNotes = 255;
}
namespace buzzer
{
    struct Note
    {
        const static int kSixteenthTriplet = 167;
        const static int kSixteenth = 250;
        const static int kEighthTriplet = 333;
        const static int kDottedSixteenght = 375;
        const static int kEighth = 500;
        const static int kQuarterTriplet = 667;
        const static int kDottedEighth = 750;
        const static int kQuarter = 1000;
        const static int kHalfTriplet = 1333;
        const static int kDottedQuarter = 1500;
        const static int kHalf = 2000;
        const static int kWholeTriplet = 2667;
        const static int kDottedHalf = 3000;
        const static int kWhole = 4000;
    };

    class Song
    {
    public:
        explicit Song(int tempo, int pin);
        // ~Song();

        void AddNote(int frequency, int value);
        void SetTempo(int tempo);
        void Reset();

        void Start();
        void Stop();
        void Pause();

        void Update();

    private:
        bool playing;
        int array_position;
        unsigned long previous_time;
        int buzzer_pin;
        int tempo;
        unsigned long note_started;
        int current_note;
        int total_notes;
        int frequencies[kMaxNotes];
        int times[kMaxNotes];
    };
}