<?php

function create_table() {
		
	$value_send = $_GET["numero"];
	
	$data = array();
	 $ar = range (0, $value_send);
    unset ($ar[0]);
    $lim =ceil(sqrt($value_send));
    {
        for ($i=2; $i<$lim; $i++)
        {
            if (isset($ar[$i]))
            for ($j=2*$i; $j<=$value_send; $j+=$i)
            {
                unset($ar[$j]);
            }
        }
    }
		
		$data = $ar;
		
	$data_content = '
	<table width="200" border="1" cellspacing="2" cellpadding="2">
	    ';
	  $max_data = sizeof($data);
	  $ctr = 1;
	  foreach ($data as $db_data) {
	    if ($ctr % 2 == 0)
	      $data_content .= '<td style="border:1px solid #000">' . $db_data . '</td></tr>';
	    else {
	      if ($ctr < $max_data)
	        $data_content .= '
	    <tr style="border:1px solid #000">
	        <td>' . $db_data . '</td>';
	      else
	        $data_content .= '
	    <tr style="border:1px solid #000">
	        <td colspan="2">' . $db_data . '</td>
	    </tr>';
	    }
	    $ctr++;
	  }
	  return $data_content . '
	</table>';
	$output = drupal_render($data_content);
		
	return $output;
 
}