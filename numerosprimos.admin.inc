
<?php

function numerosprimos_form(){
  $form = array();
	
	

  $form['value_one'] = array(
    '#type' => 'textfield',
    '#title' => t('Ingrese Valor'),
    '#description' => t('Valor a Ingresar'),
    '#default_value' => variable_get('value_one', ''),
    
  );
	
	
	$form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Enviar'),
    
  );
	
	  $form['#validate'][] = 'numerosprimos_validate';
	
	return $form;
}


function numerosprimos_validate($form, &$form_state) {
	
	
	 if ($form_state["values"]["value_one"] == "") {
       form_set_error('value_one', 'Ingrese Valor');
    }
}
  

function numerosprimos_form_submit($form, &$form_state) {
	$value_input = $form_state["values"]["value_one"];
	drupal_goto("http://localhost/DemosDrupal7/admin/settings/rootstack/numbers/generados?numero=".$value_input);
    
}

