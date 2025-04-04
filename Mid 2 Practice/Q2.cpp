#include <iostream>
#include <string>
using namespace std;

class AudioFormat{
    public:
        virtual void LoadFile(const string& filename) = 0;
        virtual void Play() = 0;
        virtual ~AudioFormat(){};
        virtual int getBitRate() const {
            return 128;  // Default bit rate for formats
        }
};

class MP3Format :  public AudioFormat{
    public:
        void LoadFile (const string& filename) override{
            cout << "Loading MP3 File:" << filename << endl;
        }
        void Play () override{
            cout << "Playing MP3 File." << endl;
        }
};

class FLACFormat :  public AudioFormat{
    public:
        void LoadFile (const string& filename) override{
            cout << "Loading FLAC File:" << filename << endl;
        }
        void Play () override{
            cout << "Playing FLAC File." << endl;
        }
        // For part 5 testing birrate function over riding
        int getBitRate() const override {
            return 1000;  
        }
};

class WAVFormat :  public AudioFormat{
    public:
        void LoadFile (const string& filename) override{
            cout << "Loading WAV File:" << filename << endl;
        }
        void Play () override{
            cout << "Playing WAV File." << endl;
        }
};
/*
Q)What design benefit do you get by making AudioFormat an abstract class instead of a concrete base class?
All audio format classes must implement the loadFile() and play() methods, ensuring a consistent interface across different audio formats.
If we need to add new formats we could simply create dervied classes that will be implementing reqired methods.

Q)Suppose you want to add a new function getBitRate() to all audio formats, but you do not want to break existing code. How would you incorporate this function while maintaining backward compatibility?
We will smply write this function in the base class as virrtual. Than any derived class does needs the baalue changed can simply over ride it, those that doesnt want to can simply skip this or use the default value if set.
*/
int main(){
    MP3Format mp3;
    FLACFormat flac;
    WAVFormat wav;

    AudioFormat* audio1 = &mp3;
    AudioFormat* audio2 = &flac;
    AudioFormat* audio3 = &wav;

    // Demonstrating runtime polymorphism
    audio1->LoadFile("song.mp3");
    audio1->Play();
    cout << audio1->getBitRate() << endl; // Default

    audio2->LoadFile("track.flac");
    audio2->Play();
    cout << audio2->getBitRate() << endl;   // Over ridden value

    audio3->LoadFile("sound.wav");
    audio3->Play();
    cout << audio3->getBitRate() << endl; // Default
}
