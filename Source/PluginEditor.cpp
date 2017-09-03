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
: AudioProcessorEditor (p),
//processor (p), // not required if we have the getProcesson() methon implemented
//d(new DragAndDrop(*(p.filepath))), // could be initialized in the initialization list

fileFilter ("*.jpeg;*.jpg;*.png;*.gif", "*", "Image Filter"),
fileDirectoryThread ("Image File Scanner"),
dirContentsList (&fileFilter, fileDirectoryThread),
fileTree (dirContentsList),
resizerTop (&layout, 1, false),
resizerBottom(&layout, 1, false)

{
    pathOrFile = *(p.filepath);
    dragDropComponent = new DragAndDrop(*(p.filepath));
    addAndMakeVisible(dragDropComponent);
    setOpaque (true);
    dirContentsList.setDirectory (pathOrFile, true, true);
    fileDirectoryThread.startThread (1);
    
    fileTree.addListener (this);
    
    fileTree.setColour (TreeView::backgroundColourId, Colours::whitesmoke.withAlpha (0.6f));
    
    addAndMakeVisible (resizerTop);
    
    addAndMakeVisible (fileTree);
    
    addAndMakeVisible (resizerBottom);
    
    addAndMakeVisible (imagePreview);
    
    if (*(p.comments) != "") {
        textbox.setText(*(p.comments));
    }
    
    textbox.setColour(TextEditor::backgroundColourId, Colours::lightgrey);
    textbox.setColour(TextEditor::textColourId, Colours::darkgrey);
    textbox.setMultiLine(true);
    textbox.setReturnKeyStartsNewLine(true);
    textbox.setScrollbarsShown(true);
    textbox.setTextToShowWhenEmpty("Add your comments here...", Colours::grey);
    addAndMakeVisible (textbox);
    
    // d&d
    layout.setItemLayout (0, -0.05, -0.1, -0.1);
    
    // resizerTop
    layout.setItemLayout (1, 3, 3, 3);
    
    // fileTree
    layout.setItemLayout (2, -0.1, -0.9, -0.3);
    
    // resizerBottom
    layout.setItemLayout (3, 3, 3, 3);
    
    // imagePreview
    layout.setItemLayout (4, -0.1, -0.9, -0.55);
    
    // textbox
    layout.setItemLayout (5, -0.1, -0.9, -0.1);
    
    setResizable(true, true);
    
    
    setSize (p.lastUIWidth, p.lastUIHeight);
    setResizeLimits (400, 400, 1200, 600);
}

ImagesDragDropAudioProcessorEditor::~ImagesDragDropAudioProcessorEditor()
{
    if (!textbox.isEmpty()) {
        *(getProcessor().comments) = textbox.getText();
    }
    fileTree.removeListener (this);

    delete dragDropComponent;
}

//==============================================================================
void ImagesDragDropAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::darkgrey);   // clear the background
    g.setColour (Colours::black);
    g.drawRect (getLocalBounds(), 0.5);
    browserRootChanged(dragDropComponent->getPath());
    *(getProcessor().filepath) = dragDropComponent->getPath();
}

void ImagesDragDropAudioProcessorEditor::resized()
{
    // subcomponents in your editor..
    Rectangle<int> r (getLocalBounds());
    //
    // make a list of two of our child components that we want to reposition
    Component* comps[] = { dragDropComponent, &resizerTop, &fileTree, &resizerBottom, &imagePreview, &textbox };
    
    // this will position the 3 components, one above the other, to fit
    // vertically into the rectangle provided.
    layout.layOutComponents (comps, 6, r.getX(), r.getY(), r.getWidth(), r.getHeight(), true, true);
    
    getProcessor().lastUIWidth = getWidth();
    getProcessor().lastUIHeight = getHeight();
    
}
