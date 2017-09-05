/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//#include "./DragAndDrop.cpp"

//==============================================================================
/**
*/

class DragAndDrop;

class ImagesDragDropAudioProcessorEditor  : public AudioProcessorEditor,
public FileBrowserListener, public DragAndDropContainer, public DragAndDropTarget,
public FileDragAndDropTarget
{
public:
    ImagesDragDropAudioProcessorEditor (ImagesDragDropAudioProcessor&);
    ~ImagesDragDropAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    friend class DragAndDrop;
   
    void selectionChanged() override {
        
        const File selectedFile (fileTree.getSelectedFile());
        
        if (selectedFile.existsAsFile())
            imagePreview.setImage (ImageCache::getFromFile (selectedFile));
    }

    void browserRootChanged (const File& f) override {
        dirContentsList.setDirectory (f, true, true);
    }
    
    //==============================================================================
    // These methods implement the FileDragAndDropTarget interface, and allow our component
    // to accept drag-and-drop of files..
    
    bool isInterestedInFileDrag (const StringArray& /*files*/) override
    {
        // normally you'd check these files to see if they're something that you're
        // interested in before returning true, but for the demo, we'll say yes to anything..
        return true;
    }
    
    void fileDragEnter (const StringArray& /*files*/, int /*x*/, int /*y*/) override
    {
        smthIsBeingDraggedOver = true;
        repaint();
    }
    
    void fileDragMove (const StringArray& /*files*/, int /*x*/, int /*y*/) override
    {
    }
    
    void fileDragExit (const StringArray& /*files*/) override
    {
        smthIsBeingDraggedOver = false;
        repaint();
    }
    
    // this one is called in the plug-in
    void filesDropped (const StringArray& files, int /*x*/, int /*y*/) override ;
    void itemDropped (const SourceDetails& dragSourceDetails) override
    {
        
    }
    
    bool isInterestedInDragSource (const SourceDetails& /*dragSourceDetails*/) override
    {
        // normally you'd check the sourceDescription value to see if it's the
        // sort of object that you're interested in before returning true, but for
        // the demo, we'll say yes to anything..
        return true;
    }
    
    void itemDragEnter (const SourceDetails& /*dragSourceDetails*/) override
    {
        smthIsBeingDraggedOver = true;
        repaint();
    }
    
    void itemDragMove (const SourceDetails& /*dragSourceDetails*/) override
    {
    }
    
    void itemDragExit (const SourceDetails& /*dragSourceDetails*/) override
    {
        smthIsBeingDraggedOver = false;
        repaint();
    }
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DragAndDrop* dragDropComponent;
    String pathOrFile;
    
   // ImagesDragDropAudioProcessor& processor;
    WildcardFileFilter fileFilter;
    TimeSliceThread fileDirectoryThread;
    DirectoryContentsList dirContentsList;
    StretchableLayoutManager layout;
    FileTreeComponent fileTree;
    bool smthIsBeingDraggedOver;
    
    ImageComponent imagePreview;
    
    TextEditor textbox;
    
    StretchableLayoutResizerBar resizerTop;
    //StretchableLayoutResizerBar resizerMid;
    StretchableLayoutResizerBar resizerBottom;
    

    
    void fileClicked (const File&, const MouseEvent&) override {}
    void fileDoubleClicked (const File&) override {}


    ImagesDragDropAudioProcessor& getProcessor() const
    {
        return static_cast<ImagesDragDropAudioProcessor&> (processor);
    }
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImagesDragDropAudioProcessorEditor)
};

class DragAndDrop :
public Component,
public DragAndDropTarget,
public FileDragAndDropTarget,
public TextDragAndDropTarget
{
public:

    
    DragAndDrop(const String& mypath): message("Drag and Drop Folder or Files to Copy HERE!\nCurrent Directory: " + String(mypath)), path(mypath) {
        
    }
 
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);

        // draw a red line around the comp if the user's currently dragging something over it..
        if (somethingIsBeingDraggedOver)
        {
            g.setColour (Colours::white);
            g.drawRect (getLocalBounds(), 1);
            //g.drawFittedText ("", getLocalBounds().reduced (10, 0), Justification::centred, 4);
        }
        
        g.setColour (Colours::darkgrey);
        g.setFont (14.0f);
        g.drawFittedText (message, getLocalBounds().reduced (10, 0), Justification::centred, 4);
        
       
    }

    //==============================================================================
    // These methods implement the DragAndDropTarget interface, and allow our component
    // to accept drag-and-drop of objects from other Juce components..
    
    bool isInterestedInDragSource (const SourceDetails& /*dragSourceDetails*/) override
    {
        // normally you'd check the sourceDescription value to see if it's the
        // sort of object that you're interested in before returning true, but for
        // the demo, we'll say yes to anything..
        return true;
    }
    
    void itemDragEnter (const SourceDetails& /*dragSourceDetails*/) override
    {
        somethingIsBeingDraggedOver = true;
        repaint();
    }
    
    void itemDragMove (const SourceDetails& /*dragSourceDetails*/) override
    {
    }
    
    void itemDragExit (const SourceDetails& /*dragSourceDetails*/) override
    {
        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    void itemDropped (const SourceDetails& dragSourceDetails) override
    {
        
        message = "Current directory: " + dragSourceDetails.description.toString();
        path = dragSourceDetails.description.toString();
        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    //==============================================================================
    // These methods implement the FileDragAndDropTarget interface, and allow our component
    // to accept drag-and-drop of files..
    
    bool isInterestedInFileDrag (const StringArray& /*files*/) override
    {
        // normally you'd check these files to see if they're something that you're
        // interested in before returning true, but for the demo, we'll say yes to anything..
        return true;
    }
    
    void fileDragEnter (const StringArray& /*files*/, int /*x*/, int /*y*/) override
    {
        somethingIsBeingDraggedOver = true;
        repaint();
    }
    
    void fileDragMove (const StringArray& /*files*/, int /*x*/, int /*y*/) override
    {
    }
    
    void fileDragExit (const StringArray& /*files*/) override
    {
        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    // this one is called in the plug-in
    void filesDropped (const StringArray& files, int /*x*/, int /*y*/) override
    {
        //function
        //repaint after the files are copied
        File file;
        if (files.size() == 1) {
            file = files[0];
            if (file.isDirectory()) { // update path only if 1 directory is dropped
                path = files.joinIntoString("\n");
            } else {
                copyFilesToCurrentDirectory(files);
            }
        } else if (files.size() > 0) {
            copyFilesToCurrentDirectory(files);
        }
        message = "Current directory: " + path;

        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    //==============================================================================
    // These methods implement the TextDragAndDropTarget interface, and allow our component
    // to accept drag-and-drop of text..
    
    bool isInterestedInTextDrag (const String& /*text*/) override
    {
        return true;
    }
    
    void textDragEnter (const String& /*text*/, int /*x*/, int /*y*/) override
    {
        somethingIsBeingDraggedOver = true;
        repaint();
    }
    
    void textDragMove (const String& /*text*/, int /*x*/, int /*y*/) override
    {
    }
    
    void textDragExit (const String& /*text*/) override
    {
        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    void textDropped (const String& text, int /*x*/, int /*y*/) override
    {
        message = "Text dropped:\n" + text;
        
        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    String getMess() const {
        return message;
    }
    
    String getPath() const {
        return path;
    }
    
    void setPath(const String& newPath) {
        path = newPath;
    }
    
    void setMess(const String& newMess) {
        message = newMess;
    }
    
    void copyFilesToCurrentDirectory(const StringArray& files) {
        File file;
        String destinationPath;
        String ext;
        String pathToCopy = path;
        File pathCopy = path;
        
        for (int i = 0; i < files.size(); ++i) {
            file = files[i];
            if (!file.isDirectory()) {
                ext = file.getFileExtension();
                if (pathCopy.hasWriteAccess() && (ext == ".jpeg" || ext == ".jpg" || ext == ".png" || ext == ".gif")) {
                    destinationPath = pathToCopy + "/" + file.getFileName();
                    filetreeChanged = file.copyFileTo(destinationPath);
                }
            }
        }
    }
    
    bool getFiletreeChanged() const {
        return filetreeChanged;
    }
    
    void setFiletreeChanged(bool newBool) {
        filetreeChanged = newBool;
    }
    
private:
    bool filetreeChanged;
    String message;
    String path;
    StretchableLayoutManager layout;
    bool somethingIsBeingDraggedOver;
};

#endif  // PLUGINEDITOR_H_INCLUDED

