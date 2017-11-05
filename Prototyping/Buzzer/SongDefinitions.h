
#include "Song.h"

namespace buzzer
{
    void MaryHadALittleLamb(Song& song)
    {
        song.Reset();
        song.SetTempo(120);
        
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kC4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kE4, buzzer::Note::kHalf);
    
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kHalf);
    
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kG4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kG4, buzzer::Note::kHalf);
    
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kC4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
    
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
    
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kE4, buzzer::Note::kQuarter);
        song.AddNote(MusicNote::kD4, buzzer::Note::kQuarter);
    
        song.AddNote(MusicNote::kC4, buzzer::Note::kWhole);
    }

    void StarWars(Song& song)
    {
        song.Reset();
        song.SetTempo(132);

        song.AddNote(MusicNote::kD4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kD4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kD4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kG4, Note::kHalf);
        song.AddNote(MusicNote::kD5, Note::kHalf);

        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kA4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kG5, Note::kHalf);
        song.AddNote(MusicNote::kD5, Note::kQuarter);

        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kA4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kG5, Note::kHalf);
        song.AddNote(MusicNote::kD5, Note::kQuarter);

        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);

        song.AddNote(MusicNote::kA4, Note::kHalf);

        song.AddNote(MusicNote::kD4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kD4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kD4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kG4, Note::kHalf);
        song.AddNote(MusicNote::kD5, Note::kHalf);

        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kA4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kG5, Note::kHalf);
        song.AddNote(MusicNote::kD5, Note::kQuarter);

        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kA4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kG5, Note::kHalf);
        song.AddNote(MusicNote::kD5, Note::kQuarter);

        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kC5, Note::kEighthTriplet);

        song.AddNote(MusicNote::kA4, Note::kHalf);

        song.AddNote(MusicNote::kD4, Note::kDottedEighth);
        song.AddNote(MusicNote::kD4, Note::kSixteenth);

        song.AddNote(MusicNote::kE4, Note::kDottedQuarter);
        song.AddNote(MusicNote::kE4, Note::kEighth);

        song.AddNote(MusicNote::kC5, Note::kEighth);
        song.AddNote(MusicNote::kB4, Note::kEighth);
        song.AddNote(MusicNote::kA4, Note::kEighth);
        song.AddNote(MusicNote::kG4, Note::kEighth);

        song.AddNote(MusicNote::kG4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kA4, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB4, Note::kEighthTriplet);

        song.AddNote(MusicNote::kA4, Note::kDottedEighth);
        song.AddNote(MusicNote::kE4, Note::kSixteenth);
        song.AddNote(MusicNote::kF4Sharp, Note::kQuarter);

        song.AddNote(MusicNote::kD4, Note::kDottedEighth);
        song.AddNote(MusicNote::kD4, Note::kSixteenth);

        song.AddNote(MusicNote::kE4, Note::kDottedQuarter);
        song.AddNote(MusicNote::kE4, Note::kEighth);

        song.AddNote(MusicNote::kC5, Note::kEighth);
        song.AddNote(MusicNote::kB4, Note::kEighth);
        song.AddNote(MusicNote::kA4, Note::kEighth);
        song.AddNote(MusicNote::kG4, Note::kEighth);

        song.AddNote(MusicNote::kD5, Note::kDottedEighth);

        song.AddNote(MusicNote::kA4, Note::kSixteenth);
        song.AddNote(MusicNote::kA4, Note::kHalf);

        // Octave up
        song.AddNote(MusicNote::kD5, Note::kDottedEighth);
        song.AddNote(MusicNote::kD5, Note::kSixteenth);

        song.AddNote(MusicNote::kE5, Note::kDottedQuarter);
        song.AddNote(MusicNote::kE5, Note::kEighth);

        song.AddNote(MusicNote::kC6, Note::kEighth);
        song.AddNote(MusicNote::kB5, Note::kEighth);
        song.AddNote(MusicNote::kA5, Note::kEighth);
        song.AddNote(MusicNote::kG5, Note::kEighth);

        song.AddNote(MusicNote::kG5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kA5, Note::kEighthTriplet);
        song.AddNote(MusicNote::kB5, Note::kEighthTriplet);

        song.AddNote(MusicNote::kA5, Note::kDottedEighth);
        song.AddNote(MusicNote::kE5, Note::kSixteenth);
        song.AddNote(MusicNote::kF5Sharp, Note::kQuarter);

        song.AddNote(MusicNote::kD5, Note::kDottedEighth);
        song.AddNote(MusicNote::kD5, Note::kSixteenth);

        // Descent
        song.AddNote(MusicNote::kG5, Note::kDottedEighth);
        song.AddNote(MusicNote::kF5, Note::kSixteenth);
        song.AddNote(MusicNote::kD5Sharp, Note::kDottedEighth);
        song.AddNote(MusicNote::kD5, Note::kSixteenth);
        song.AddNote(MusicNote::kC4, Note::kDottedEighth);
        song.AddNote(MusicNote::kA4Sharp, Note::kSixteenth);
        song.AddNote(MusicNote::kA4, Note::kDottedEighth);
        song.AddNote(MusicNote::kG4, Note::kSixteenth);

        song.AddNote(MusicNote::kD5, Note::kDottedHalf);
    }

    void Valkyries(Song& song)
    {
        song.Reset();
        song.SetTempo(132);

        song.AddNote(MusicNote::kF4Sharp, Note::kEighth);

        song.AddNote(MusicNote::kB4, Note::kDottedEighth);
        song.AddNote(MusicNote::kF4Sharp, Note::kSixteenth);
        song.AddNote(MusicNote::kB4, Note::kEighth);

        song.AddNote(MusicNote::kD5, Note::kDottedQuarter);
        song.AddNote(MusicNote::kB4, Note::kDottedQuarter);

        song.AddNote(MusicNote::kD5, Note::kDottedEighth);
        song.AddNote(MusicNote::kB4, Note::kSixteenth);
        song.AddNote(MusicNote::kD5, Note::kEighth);

        song.AddNote(MusicNote::kF5Sharp, Note::kDottedQuarter);
        song.AddNote(MusicNote::kD5, Note::kDottedQuarter);

        song.AddNote(MusicNote::kF5Sharp, Note::kDottedEighth);
        song.AddNote(MusicNote::kD5, Note::kSixteenth);
        song.AddNote(MusicNote::kF5Sharp, Note::kEighth);

        song.AddNote(MusicNote::kA5, Note::kDottedQuarter);
        song.AddNote(MusicNote::kA4, Note::kDottedQuarter);

        song.AddNote(MusicNote::kD5, Note::kDottedEighth);
        song.AddNote(MusicNote::kA4, Note::kSixteenth);
        song.AddNote(MusicNote::kD5, Note::kEighth);

        song.AddNote(MusicNote::kF5Sharp, Note::kDottedHalf);

        // Repeat 
        song.AddNote(MusicNote::kA4, Note::kEighth);
        
        song.AddNote(MusicNote::kD5, Note::kDottedEighth);
        song.AddNote(MusicNote::kA4, Note::kSixteenth);
        song.AddNote(MusicNote::kD5, Note::kEighth);

        song.AddNote(MusicNote::kF5Sharp, Note::kDottedQuarter);
        song.AddNote(MusicNote::kD5, Note::kDottedQuarter);

        song.AddNote(MusicNote::kF5Sharp, Note::kDottedEighth);
        song.AddNote(MusicNote::kD5, Note::kSixteenth);
        song.AddNote(MusicNote::kF5Sharp, Note::kEighth);

        song.AddNote(MusicNote::kA5, Note::kDottedQuarter);
        song.AddNote(MusicNote::kF5Sharp, Note::kDottedQuarter);

        song.AddNote(MusicNote::kA5, Note::kDottedEighth);
        song.AddNote(MusicNote::kF5Sharp, Note::kSixteenth);
        song.AddNote(MusicNote::kA5, Note::kEighth);

        song.AddNote(MusicNote::kC6Sharp, Note::kDottedQuarter);
        song.AddNote(MusicNote::kC5Sharp, Note::kDottedQuarter);

        song.AddNote(MusicNote::kF5Sharp, Note::kDottedEighth);
        song.AddNote(MusicNote::kC5Sharp, Note::kSixteenth);
        song.AddNote(MusicNote::kF5Sharp, Note::kEighth);

        song.AddNote(MusicNote::kA5Sharp, Note::kDottedHalf);
    }

    void SongOfTime(Song& song)
    {
        song.Reset();
        song.SetTempo(120);

        song.AddNote(MusicNote::kA4, Note::kQuarter);
        song.AddNote(MusicNote::kD4, Note::kHalf);

        song.AddNote(MusicNote::kF4, Note::kQuarter);
        song.AddNote(MusicNote::kA4, Note::kQuarter);
        song.AddNote(MusicNote::kD4, Note::kHalf);

        song.AddNote(MusicNote::kF4, Note::kQuarter);
        song.AddNote(MusicNote::kA4, Note::kEighth);
        song.AddNote(MusicNote::kC5, Note::kEighth);
        song.AddNote(MusicNote::kB4, Note::kQuarter);

        song.AddNote(MusicNote::kG4, Note::kQuarter);
        song.AddNote(MusicNote::kF4, Note::kEighth);
        song.AddNote(MusicNote::kG4, Note::kEighth);
        song.AddNote(MusicNote::kA4, Note::kQuarter);

        song.AddNote(MusicNote::kD4, Note::kQuarter);
        song.AddNote(MusicNote::kC4, Note::kEighth);
        song.AddNote(MusicNote::kE4, Note::kEighth);
        song.AddNote(MusicNote::kD4, Note::kWhole);
    }
}