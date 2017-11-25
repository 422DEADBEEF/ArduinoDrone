#include "Song.h"

namespace buzzer
{
    Song::Song(int tempo, int pin) : tempo(tempo), playing(false), buzzer_pin(pin), total_notes(0), array_position(0)
    {
        pinMode(buzzer_pin, OUTPUT);
    }

    void Song::AddNote(int frequency, int value)
    {
        frequencies[array_position] = frequency;
        times[array_position] = (value * (60 / (float)tempo));
        array_position++;
        total_notes++;
    }

    void Song::SetTempo(int tempo)
    {
        this->tempo = tempo;
    }

    void Song::Reset()
    {
        array_position = 0;
        total_notes = 0;
    }

    void Song::Start()
    {
        playing = true;
        current_note = 0;
        note_started = millis();
        tone(buzzer_pin, frequencies[current_note]);
    }

    void Song::Stop()
    {
        playing = false;
        current_note = 0;
        noTone(buzzer_pin);
    }

    void Song::Pause()
    {
        playing = false;
        noTone(buzzer_pin);
    }

    void Song::Update()
    {
        if (playing)
        {
            long time_remaining = times[current_note] - (millis() - note_started);

            if (time_remaining <= 20)
            {
                noTone(buzzer_pin);
            }

            if (time_remaining <= 0)
            {
                current_note++;
                if (current_note > total_notes)
                {
                    Stop();
                    return;
                }
                tone(buzzer_pin, frequencies[current_note]);
                note_started = millis();
            }
        }
    }
}