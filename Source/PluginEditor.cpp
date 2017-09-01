/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ImagesDragDropAudioProcessorEditor::ImagesDragDropAudioProcessorEditor (ImagesDragDropAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p),
//d(new DragAndDrop),
d(new DragAndDrop(p.filepath)),
fileFilter ("*.jpeg;*.jpg;*.png;*.gif", "*", "Image Filter"),
fileDirectoryThread ("Image File Scanner"),
dirContentsList (&fileFilter, fileDirectoryThread),
fileTree (dirContentsList),
resizer (&layout, 1, false)
{
    path_or_file = p.filepath;
    addAndMakeVisible(d);
    setOpaque (true);
    dirContentsList.setDirectory (path_or_file, true, true);
    fileDirectoryThread.startThread (1);
    
    fileTree.addListener (this);
    fileTree.setRepaintsOnMouseActivity(true);
    fileTree.setColour (TreeView::backgroundColourId, Colours::whitesmoke.withAlpha (0.6f));
    
    addAndMakeVisible (fileTree);
    
    addAndMakeVisible (resizer);
    
    addAndMakeVisible (imagePreview);
    
    // d&d
    layout.setItemLayout (0, -0.1, -0.9, -0.1);
    
    // fileTree
    layout.setItemLayout (1, -0.1, -0.9, -0.4);
    
    // resizer
    layout.setItemLayout (2, 3, 3, 3);
    
    // imagePreview
    layout.setItemLayout (3, -0.1, -0.9, -0.5);
    
    
    setResizeLimits (400, 400, 1200, 600);
    setSize (p.lastUIWidth, p.lastUIHeight);
    
}

ImagesDragDropAudioProcessorEditor::~ImagesDragDropAudioProcessorEditor()
{
 //   processor.filepath = d->getPath();
    
    fileTree.removeListener (this);
    
    delete d;
}

//==============================================================================
void ImagesDragDropAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);   // clear the background
    g.setColour (Colours::black);
    g.drawRect (getLocalBounds(), 0.5);
//    browserRootChanged(d->getPath());
  //  fileTree.refresh();
//    if (smthIsBeingDraggedOver)
//    {
//        g.setColour (Colours::red);
//        g.drawRect (getLocalBounds(), 3);
//    }
}

void ImagesDragDropAudioProcessorEditor::resized()
{
    // subcomponents in your editor..
    Rectangle<int> r (getLocalBounds());
    //
    // make a list of two of our child components that we want to reposition
    Component* comps[] = { d, &fileTree, &resizer, &imagePreview };
    
    // this will position the 3 components, one above the other, to fit
    // vertically into the rectangle provided.
    layout.layOutComponents (comps, 4, r.getX(), r.getY(), r.getWidth(), r.getHeight(), true, true);
    
    getProcessor().lastUIWidth = getWidth();
    getProcessor().lastUIHeight = getHeight();
    
    

}
//void ImagesDragDropAudioProcessorEditor::browserRootChanged (const File& dir)  {
//    if (d->somethingIsBeingDraggedOver) {
//        dirContentsList.setDirectory(dir, true, true);
//        
//        
//    }
//    fileTree.refresh();
//    
//}
