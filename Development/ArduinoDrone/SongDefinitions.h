
#include "Song.h"

namespace buzzer
{

    void MaryHadALittleLamb(Song& song)
    {
        song.Reset();
        song.SetTempo(120);
        
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kC4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
        
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kE4, Note::kHalf);
    
        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kD4, Note::kHalf);
    
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kG4, Note::kQuarter);
        song.AddNote(kG4, Note::kHalf);
    
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kC4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
    
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kE4, Note::kQuarter);
    
        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kE4, Note::kQuarter);
        song.AddNote(kD4, Note::kQuarter);
    
        song.AddNote(kC4, Note::kWhole);
    }

    void StarWars(Song& song)
    {
        song.Reset();
        song.SetTempo(132);

        song.AddNote(kD4, Note::kEighthTriplet);
        song.AddNote(kD4, Note::kEighthTriplet);
        song.AddNote(kD4, Note::kEighthTriplet);

        song.AddNote(kG4, Note::kHalf);
        song.AddNote(kD5, Note::kHalf);

        song.AddNote(kC5, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);
        song.AddNote(kA4, Note::kEighthTriplet);

        song.AddNote(kG5, Note::kHalf);
        song.AddNote(kD5, Note::kQuarter);

        song.AddNote(kC5, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);
        song.AddNote(kA4, Note::kEighthTriplet);

        song.AddNote(kG5, Note::kHalf);
        song.AddNote(kD5, Note::kQuarter);

        song.AddNote(kC5, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);
        song.AddNote(kC5, Note::kEighthTriplet);

        song.AddNote(kA4, Note::kHalf);

        song.AddNote(kD4, Note::kEighthTriplet);
        song.AddNote(kD4, Note::kEighthTriplet);
        song.AddNote(kD4, Note::kEighthTriplet);

        song.AddNote(kG4, Note::kHalf);
        song.AddNote(kD5, Note::kHalf);

        song.AddNote(kC5, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);
        song.AddNote(kA4, Note::kEighthTriplet);

        song.AddNote(kG5, Note::kHalf);
        song.AddNote(kD5, Note::kQuarter);

        song.AddNote(kC5, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);
        song.AddNote(kA4, Note::kEighthTriplet);

        song.AddNote(kG5, Note::kHalf);
        song.AddNote(kD5, Note::kQuarter);

        song.AddNote(kC5, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);
        song.AddNote(kC5, Note::kEighthTriplet);

        song.AddNote(kA4, Note::kHalf);

        song.AddNote(kD4, Note::kDottedEighth);
        song.AddNote(kD4, Note::kSixteenth);

        song.AddNote(kE4, Note::kDottedQuarter);
        song.AddNote(kE4, Note::kEighth);

        song.AddNote(kC5, Note::kEighth);
        song.AddNote(kB4, Note::kEighth);
        song.AddNote(kA4, Note::kEighth);
        song.AddNote(kG4, Note::kEighth);

        song.AddNote(kG4, Note::kEighthTriplet);
        song.AddNote(kA4, Note::kEighthTriplet);
        song.AddNote(kB4, Note::kEighthTriplet);

        song.AddNote(kA4, Note::kDottedEighth);
        song.AddNote(kE4, Note::kSixteenth);
        song.AddNote(kF4Sharp, Note::kQuarter);

        song.AddNote(kD4, Note::kDottedEighth);
        song.AddNote(kD4, Note::kSixteenth);

        song.AddNote(kE4, Note::kDottedQuarter);
        song.AddNote(kE4, Note::kEighth);

        song.AddNote(kC5, Note::kEighth);
        song.AddNote(kB4, Note::kEighth);
        song.AddNote(kA4, Note::kEighth);
        song.AddNote(kG4, Note::kEighth);

        song.AddNote(kD5, Note::kDottedEighth);

        song.AddNote(kA4, Note::kSixteenth);
        song.AddNote(kA4, Note::kHalf);

        // Octave up
        song.AddNote(kD5, Note::kDottedEighth);
        song.AddNote(kD5, Note::kSixteenth);

        song.AddNote(kE5, Note::kDottedQuarter);
        song.AddNote(kE5, Note::kEighth);

        song.AddNote(kC6, Note::kEighth);
        song.AddNote(kB5, Note::kEighth);
        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kG5, Note::kEighth);

        song.AddNote(kG5, Note::kEighthTriplet);
        song.AddNote(kA5, Note::kEighthTriplet);
        song.AddNote(kB5, Note::kEighthTriplet);

        song.AddNote(kA5, Note::kDottedEighth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kQuarter);

        song.AddNote(kD5, Note::kDottedEighth);
        song.AddNote(kD5, Note::kSixteenth);

        // Descent
        song.AddNote(kG5, Note::kDottedEighth);
        song.AddNote(kF5, Note::kSixteenth);
        song.AddNote(kD5Sharp, Note::kDottedEighth);
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kC4, Note::kDottedEighth);
        song.AddNote(kA4Sharp, Note::kSixteenth);
        song.AddNote(kA4, Note::kDottedEighth);
        song.AddNote(kG4, Note::kSixteenth);

        song.AddNote(kD5, Note::kDottedHalf);
    }

    void Valkyries(Song& song)
    {
        song.Reset();
        song.SetTempo(132);

        song.AddNote(kF4Sharp, Note::kEighth);

        song.AddNote(kB4, Note::kDottedEighth);
        song.AddNote(kF4Sharp, Note::kSixteenth);
        song.AddNote(kB4, Note::kEighth);

        song.AddNote(kD5, Note::kDottedQuarter);
        song.AddNote(kB4, Note::kDottedQuarter);

        song.AddNote(kD5, Note::kDottedEighth);
        song.AddNote(kB4, Note::kSixteenth);
        song.AddNote(kD5, Note::kEighth);

        song.AddNote(kF5Sharp, Note::kDottedQuarter);
        song.AddNote(kD5, Note::kDottedQuarter);

        song.AddNote(kF5Sharp, Note::kDottedEighth);
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kA5, Note::kDottedQuarter);
        song.AddNote(kA4, Note::kDottedQuarter);

        song.AddNote(kD5, Note::kDottedEighth);
        song.AddNote(kA4, Note::kSixteenth);
        song.AddNote(kD5, Note::kEighth);

        song.AddNote(kF5Sharp, Note::kDottedHalf);

        // Repeat 
        song.AddNote(kA4, Note::kEighth);
        
        song.AddNote(kD5, Note::kDottedEighth);
        song.AddNote(kA4, Note::kSixteenth);
        song.AddNote(kD5, Note::kEighth);

        song.AddNote(kF5Sharp, Note::kDottedQuarter);
        song.AddNote(kD5, Note::kDottedQuarter);

        song.AddNote(kF5Sharp, Note::kDottedEighth);
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kA5, Note::kDottedQuarter);
        song.AddNote(kF5Sharp, Note::kDottedQuarter);

        song.AddNote(kA5, Note::kDottedEighth);
        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kA5, Note::kEighth);

        song.AddNote(kC6Sharp, Note::kDottedQuarter);
        song.AddNote(kC5Sharp, Note::kDottedQuarter);

        song.AddNote(kF5Sharp, Note::kDottedEighth);
        song.AddNote(kC5Sharp, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kA5Sharp, Note::kDottedHalf);
    }

    void SongOfTime(Song& song)
    {
        song.Reset();
        song.SetTempo(120);

        song.AddNote(kA4, Note::kQuarter);
        song.AddNote(kD4, Note::kHalf);

        song.AddNote(kF4, Note::kQuarter);
        song.AddNote(kA4, Note::kQuarter);
        song.AddNote(kD4, Note::kHalf);

        song.AddNote(kF4, Note::kQuarter);
        song.AddNote(kA4, Note::kEighth);
        song.AddNote(kC5, Note::kEighth);
        song.AddNote(kB4, Note::kQuarter);

        song.AddNote(kG4, Note::kQuarter);
        song.AddNote(kF4, Note::kEighth);
        song.AddNote(kG4, Note::kEighth);
        song.AddNote(kA4, Note::kQuarter);

        song.AddNote(kD4, Note::kQuarter);
        song.AddNote(kC4, Note::kEighth);
        song.AddNote(kE4, Note::kEighth);
        song.AddNote(kD4, Note::kWhole);
    }
    
    void RouteOne(Song& song)
    {
        song.Reset();
        song.SetTempo(128);

        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kG5, Note::kDottedEighth);
        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kE5, Note::kDottedQuarter);

        //asdasd
        song.AddNote(kC5Sharp, Note::kSixteenth);
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kE5, Note::kEighth);

        song.AddNote(kC5Sharp, Note::kSixteenth);
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kE5, Note::kEighth);

        song.AddNote(kC5Sharp, Note::kSixteenth);
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kE5, Note::kEighth);

        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kD5, Note::kQuarter);
        song.AddNote(kF5Sharp, Note::kEighth);

        //asdasd
        
        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);

        song.AddNote(kD5, Note::kSixteenth);
        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kG5, Note::kDottedEighth);
        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kE5, Note::kDottedQuarter);

        // asdasd

        song.AddNote(kC5Sharp, Note::kSixteenth);
        song.AddNote(kD5, Note::kSixteenth);

        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kG5, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kE5, Note::kEighth);
        song.AddNote(kD5, Note::kEighth);
        song.AddNote(kC5Sharp, Note::kEighth);
        song.AddNote(kB4, Note::kEighth);
        song.AddNote(kC5, Note::kEighth);
        
        song.AddNote(kB5, Note::kQuarter);

        song.AddNote(kE5, Note::kSixteenth);
        song.AddNote(kB4, Note::kSixteenth);
        song.AddNote(kA4, Note::kSixteenth);
        song.AddNote(kC5Sharp, Note::kSixteenth);

        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kA4, Note::kEighth);
        song.AddNote(kA4, Note::kEighth);

        // asdasd

        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kG5, Note::kSixteenth);

        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kD5, Note::kEighth);

        song.AddNote(kD6, Note::kEighth);
        song.AddNote(kC6Sharp, Note::kEighth);
        song.AddNote(kB6, Note::kEighth);
        song.AddNote(kC6Sharp, Note::kEighth);

        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kD5, Note::kDottedEighth);
        song.AddNote(kF5Sharp, Note::kSixteenth);

        song.AddNote(kE5, Note::kDottedQuarter);

        song.AddNote(kF5Sharp, Note::kSixteenth);
        song.AddNote(kG5, Note::kSixteenth);

        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kF5Sharp, Note::kEighth);
        song.AddNote(kA5, Note::kEighth);

        song.AddNote(kD6, Note::kEighth);
        song.AddNote(kC6Sharp, Note::kEighth);
        song.AddNote(kA5, Note::kDottedEighth);
        song.AddNote(kG5, Note::kSixteenth);

        song.AddNote(kA5, Note::kEighth);
        song.AddNote(kD6, Note::kEighth);
        song.AddNote(kC6Sharp, Note::kEighth);
        song.AddNote(kE6, Note::kEighth);

        song.AddNote(kD6, Note::kQuarter);
    }
}