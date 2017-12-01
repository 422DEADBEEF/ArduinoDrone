#include "Arduino.h"
#include "Frequencies.h"

#define kMaxNotes 64

#define kSixteenthTriplet 167
#define kSixteenth 250
#define kEighthTriplet 333
#define kDottedSixteenght 375
#define kEighth 500
#define kQuarterTriplet 667
#define kDottedEighth 750
#define kQuarter 1000
#define kHalfTriplet 1333
#define kDottedQuarter 1500
#define kHalf 2000
#define kWholeTriplet 2667
#define kDottedHalf 3000
#define kWhole 4000

namespace buzzer
{
    class Song
    {
    public:
        explicit Song(int tempo, int pin);

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
        uint16_t frequencies[kMaxNotes];
        uint16_t times[kMaxNotes];
    };
}