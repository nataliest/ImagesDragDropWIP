/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#ifndef DRAGANDDROP_CPP_INCLUDED
#define DRAGANDDROP_CPP_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//#include "./DragAndDrop.cpp"

//==============================================================================
/**
*/

class DragAndDrop;

class ImagesDragDropAudioProcessorEditor  : public AudioProcessorEditor,
public FileBrowserListener, public DragAndDropContainer
, public DragAndDropTarget, public FileDragAndDropTarget
{
public:
    ImagesDragDropAudioProcessorEditor (ImagesDragDropAudioProcessor&);
    ~ImagesDragDropAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    friend class DragAndDrop;
//    void fileClicked (const File&, const MouseEvent&) override {}
//    void fileDoubleClicked (const File&) override {}
//    void browserRootChanged (const File& dir) override {
//        //const File selectedRoot (fileTree.getRootItem());
//        
//        dirContentsList.setDirectory(dir, true, true);
//        
//        //fileTree.setDragAndDropDescription();
//        fileTree.refresh();
//   //     if (d->somethingIsBeingDraggedOver) {
//                    dirContentsList.setDirectory(dir, true, true);
//            
//            
//                }
//    //   fileTree.fileTree.refresh();
//    }
//    
    void itemDropped (const SourceDetails& dragSourceDetails) override
    {
        path_or_file = dragSourceDetails.description.toString();
    //    browserRootChanged (dragSourceDetails.description);
        smthIsBeingDraggedOver = false;
        repaint();
    }
    bool isInterestedInDragSource (const SourceDetails& /*dragSourceDetails*/) override
    {
        // normally you'd check the sourceDescription value to see if it's the
        // sort of object that you're interested in before returning true, but for
        // the demo, we'll say yes to anything..
        return true;
    }
//
//    void itemDragEnter (const SourceDetails& /*dragSourceDetails*/) override
//    {
//        smthIsBeingDraggedOver = true;
//        repaint();
//    }
//    
//    void itemDragMove (const SourceDetails& /*dragSourceDetails*/) override
//    {
//    }
//    
//    void itemDragExit (const SourceDetails& /*dragSourceDetails*/) override
//    {
//        smthIsBeingDraggedOver = false;
//        repaint();
//    }
    void selectionChanged() override {}
//    
//    
//    //==============================================================================
//    // These methods implement the FileDragAndDropTarget interface, and allow our component
//    // to accept drag-and-drop of files..
//    
    bool isInterestedInFileDrag (const StringArray& /*files*/) override
    {
        // normally you'd check these files to see if they're something that you're
        // interested in before returning true, but for the demo, we'll say yes to anything..
        return true;
    }
//
//    void fileDragEnter (const StringArray& /*files*/, int /*x*/, int /*y*/) override
//    {
//        smthIsBeingDraggedOver = true;
//        repaint();
//    }
//    
//    void fileDragMove (const StringArray& /*files*/, int /*x*/, int /*y*/) override
//    {
//    }
//    
//    void fileDragExit (const StringArray& /*files*/) override
//    {
//        smthIsBeingDraggedOver = false;
//        repaint();
//    }
//
    void filesDropped (const StringArray& files, int /*x*/, int /*y*/) override
    {
     //   path = files.joinIntoString("\n");
        
        smthIsBeingDraggedOver = false;
        repaint();
    }
    void browserRootChanged (const File& f) override {dirContentsList.setDirectory (f, true, true);}
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DragAndDrop* d;
    String path_or_file;
    
    ImagesDragDropAudioProcessor& processor;
    WildcardFileFilter fileFilter;
    TimeSliceThread fileDirectoryThread;
    DirectoryContentsList dirContentsList;
    StretchableLayoutManager layout;
    FileTreeComponent fileTree;
    bool smthIsBeingDraggedOver;
    
    ImageComponent imagePreview;
    
    
    StretchableLayoutResizerBar resizer;
    

//    
    void fileClicked (const File&, const MouseEvent&) override {}
    void fileDoubleClicked (const File&) override {}

//
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
//public AudioProcessorEditor
{
public:
//    DragAndDrop(ImagesDragDropAudioProcessor& p)
//    : AudioProcessorEditor (&p), processor (p),
//    somethingIsBeingDraggedOver (false)
//    {
//        path = processor.filepath;
//        message = path;
//        
//    }
    
    DragAndDrop(const String& mypath): message("mess"), path(mypath)
//    ,
//    somethingIsBeingDraggedOver (false),
//    fileFilter ("*.jpeg;*.jpg;*.png;*.gif", "*", "Image Filter"),
//    fileDirectoryThread ("Image File Scanner"),
//    dirContentsList (&fileFilter, fileDirectoryThread),
//    fileTree (dirContentsList)
    {
//        path = processor.filepath;
    //    path_or_file = p.filepath;
    //    addAndMakeVisible(d);
//        setOpaque (true);
//        dirContentsList.setDirectory (path, true, true);
//        fileDirectoryThread.startThread (1);
//        
////        fileTree.addListener (this);
//        fileTree.setRepaintsOnMouseActivity(true);
//        fileTree.setColour (TreeView::backgroundColourId, Colours::whitesmoke.withAlpha (0.6f));
//        
//        addAndMakeVisible (fileTree);
        
    }
  //  friend class ImagesDragDropAudioProcessorEditor;
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::grey.withAlpha (1.0f));
//        // subcomponents in your editor..
//        Rectangle<int> r (getLocalBounds());
//        //
//        // make a list of two of our child components that we want to reposition
//        Component* comps[] = { &fileTree};
        
        // this will position the 3 components, one above the other, to fit
        // vertically into the rectangle provided.
//        layout.layOutComponents (comps, 1, r.getX(), r.getY(), r.getWidth(), r.getHeight(), true, true);
//        g.fillAll (Colours::darkgrey);   // clear the background
//        g.setColour (Colours::black);
//        g.drawRect (getLocalBounds(), 0.5);
        // draw a red line around the comp if the user's currently dragging something over it..
        if (somethingIsBeingDraggedOver)
        {
            g.setColour (Colours::red);
            g.drawRect (getLocalBounds(), 3);
            //g.drawFittedText ("hellloooo", getLocalBounds().reduced (10, 0), Justification::centred, 4);
        }
        
        g.setColour (getLookAndFeel().findColour (Label::textColourId));
        g.setFont (14.0f);
        g.drawFittedText ("Current Directory: " + path, getLocalBounds().reduced (10, 0), Justification::centred, 4);
        
       
    }
//    void resized() override
//    {
//        // subcomponents in your editor..
//        Rectangle<int> r (getLocalBounds());
//        //
//        // make a list of two of our child components that we want to reposition
//        Component* comps[] = { &fileTree};
//        
//        // this will position the 3 components, one above the other, to fit
//        // vertically into the rectangle provided.
//        layout.layOutComponents (comps, 1, r.getX(), r.getY(), r.getWidth(), r.getHeight(), true, true);
//        
//    
//        
//    }
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
        path = dragSourceDetails.description.toString();
  //      browserRootChanged (dragSourceDetails.description);
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
    
    void filesDropped (const StringArray& files, int /*x*/, int /*y*/) override
    {
        path = files.joinIntoString("\n");
        
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
        path = "Text dropped:\n" + text;
        
        somethingIsBeingDraggedOver = false;
        repaint();
    }
    
    String getMess() {
        return message;
    }
    
    String getPath() {
        return path;
    }
    
    bool getBool() {
        return somethingIsBeingDraggedOver;
    }
    
private:
 //   ImagesDragDropAudioProcessor& processor;
//    WildcardFileFilter fileFilter;
//    TimeSliceThread fileDirectoryThread;
//    DirectoryContentsList dirContentsList;
// //   StretchableLayoutManager layout;
//    FileTreeComponent fileTree;
    String message;
    String path;
    StretchableLayoutManager layout;
    bool somethingIsBeingDraggedOver;
};
#endif  // PLUGINEDITOR_H_INCLUDED
#endif
