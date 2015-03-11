/**
 * @file: Custom CKEditor configurations that should be loaded in the HEAD of the page right after CKEditor javascript.
 */

if(typeof(CKEDITOR) !== 'undefined') {

  CKEDITOR.config.font_names ="Cambria, Hoefler Text, Liberation Serif, Times, Times New Roman, serif;" + CKEDITOR.config.font_names;

  CKEDITOR.addStylesSet('drupal', [
    {
      name: 'Normal',
      element: 'p',
      styles: {
        color: 'inherit'
      }
    },
    {
      name: 'Header',
      element: 'h2',
      styles: { 
        'color': 'inherit',
        'padding': '10px 0px',
        'border-top': '1px solid #000',
        'border-bottom': '1px solid #000',
        'text-align': 'center',
        'font-weight': 'bold',
        'font-size': '24px'
      }
    },
    {
      name: 'Pull Quote',
      element: 'h2',
      styles: {
        'color': '#000',
        'font-family': 'Cambria, Hoefler Text, Liberation Serif, Times, Times New Roman, serif',
        'font-style': 'italic',
        'font-size': '42px',
        'background': '#fff',
        'font-weight': '300',
        'padding': '1em',
        'text-align': 'center',
        'margin': '60px 0px 60px 0px',
        'border-top': '1px dotted #bebebe',
        'border-bottom': '1px dotted #bebebe'
      }
    }
  ]);
}