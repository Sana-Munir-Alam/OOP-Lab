#include <iostream>
using namespace std;

class MediaFile{
    protected:
        string FilePath;
        double FileSize;
    public:
        MediaFile(string Path, double Size) :  FilePath(Path) , FileSize(Size){
            // Paramatrized Constrcutor
        }
        virtual void Play(){
            cout << "Playing media file: " << FilePath << endl;
        }
        virtual void Stop(){
            cout << "Stopping media file: " << FilePath << endl;
        }
        void DisplayInfo(){
            cout << "File Path: " << FilePath << ", Size: " << FileSize << " MB" << endl;
        }
};
// The diamond problem is being resolved by passing the base class a virtual inorder for one instance of the base class [MediaFile] to exist and be used everywhere.
class VisualMedia : virtual public MediaFile{
    protected:
        int ResolutionWidth;
        int ResolutionHeight;
    public:
        VisualMedia(string Path, double Size, int Width, int Height) : MediaFile(Path, Size), ResolutionWidth(Width), ResolutionHeight(Height){
            // Paramatrized Constrcutor that also calls Parent Constructor
        }
        void DisplayResolution() const{
            cout << "Resolution: " << ResolutionWidth << "x" << ResolutionHeight << endl;
        }
};
class AudioMedia : virtual public MediaFile{
    protected:
        int SampleRate;
    public:
        AudioMedia(string Path, double Size, int Rate) : MediaFile(Path, Size), SampleRate(Rate){
            // Paramatrized Constrcutor that also calls Parent Constructor
        }
        void DisplaySampleRate() const{
            cout << "Sample Rate: " << SampleRate << " Hz" << endl;
        }
};

// The video file inherits bothe the visual and audio file as it consist of both file attribute.
class VideoFile : public VisualMedia, public AudioMedia{
    public:
        VideoFile(string Path, double Size, int Width, int Height, int Rate) : MediaFile(Path, Size), VisualMedia(Path, Size, Width, Height), AudioMedia(Path, Size, Rate){
            // Paramatrized Constrcutor that also calls Parent Constructor along with the intermediate base classes.
        }
        void Play() override{   // This function overrides the Parent Class Play function by adding additional features.
            cout << "Playing video file: " << FilePath << endl;
            DisplayResolution();
            DisplaySampleRate();
        }
        void Stop() override {
            cout << "Stopping video file: " << FilePath << endl;
        }
};
// The Image File inherits only Visual Media as it is a picture and has no sound.
class ImageFile : public VisualMedia {
    public:
        ImageFile(const string& Path, double Size, int Width, int Height)
            : MediaFile(Path, Size), VisualMedia(Path, Size, Width, Height) {
                // Paramatrized Constrcutor that also calls Parent Constructor along with the intermediate base classes.
            }
    
        void Play() override { 
            cout << "Displaying Image File: " << FilePath << endl;
            DisplayResolution();
        }
        void Stop() override {
            cout << "Stopping Image File: " << FilePath << endl;
        }
};
// The Audio File inherits only Audio Media as it is a Audio and has no picture.
class AudioFile : public AudioMedia{
    public:
        AudioFile(string Path, double Size, int Rate) : MediaFile(Path, Size), AudioMedia(Path, Size, Rate){
            // Paramatrized Constrcutor that also calls Parent Constructor along with the intermediate base classes.
        }
        void Play() override{   // This function overrides the Parent Class Play function by adding additional features. Const written inorder for function to not accidentaly change object state.
            cout << "Playing Audio File: " << FilePath << endl;
            DisplaySampleRate();
        }
        void Stop() override {
            cout << "Stopping Audio File: " << FilePath << endl;
        }
};

int main(){
    VideoFile Video("Video.mp4", 250.5, 1920, 1080, 48000);
    ImageFile Image("Image.jpg", 5.2, 1280, 720);
    AudioFile Audio("Audio.mp3", 10.0, 44100);
    MediaFile *Media[] = {&Video, &Image, &Audio};
    cout << endl << "-------------------------" << endl;
    for (MediaFile* file : Media) {
        file->DisplayInfo();
        file->Play();
        file->Stop();
        cout << "-------------------------" << endl;
    }
    return 0;
}
